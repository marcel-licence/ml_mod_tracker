/*
 * Copyright (c) 2024 Marcel Licence
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Dieses Programm ist Freie Software: Sie können es unter den Bedingungen
 * der GNU General Public License, wie von der Free Software Foundation,
 * Version 3 der Lizenz oder (nach Ihrer Wahl) jeder neueren
 * veröffentlichten Version, weiter verteilen und/oder modifizieren.
 *
 * Dieses Programm wird in der Hoffnung bereitgestellt, dass es nützlich sein wird, jedoch
 * OHNE JEDE GEWÄHR,; sogar ohne die implizite
 * Gewähr der MARKTFÄHIGKEIT oder EIGNUNG FÜR EINEN BESTIMMTEN ZWECK.
 * Siehe die GNU General Public License für weitere Einzelheiten.
 *
 * Sie sollten eine Kopie der GNU General Public License zusammen mit diesem
 * Programm erhalten haben. Wenn nicht, siehe <https://www.gnu.org/licenses/>.
 */

/**
 * @file ml_mod_tracker.ino
 * @author Marcel Licence
 * @date 13.03.2024
 *
 * @brief   This is the main project file running the mod tracker
 *          Not all file mod files are compatible
 *          Please stick to the notes of the mod tracker module
 *
 *          This project was tested on the Raspberry Pi Pico, ESP32, ESP32S2, ESP8266
 */


#ifdef __CDT_PARSER__
#include <cdt.h>
#define ESP8266
#endif


#include "config.h"


#include <Arduino.h>


/*
 * Library can be found on https://github.com/marcel-licence/ML_SynthTools
 */
#include <caps_info.h>

#include <ml_types.h>

#ifdef REVERB_ENABLED
#include <ml_reverb.h>
#endif

#ifdef MAX_DELAY_Q
#include <ml_delay.h>
#endif

#include <ml_utils.h>

#ifdef OLED_OSC_DISP_ENABLED
#include <ml_scope.h>
#endif

#include "ml_tracker_mod.h"


/* create a file with const data for playback from flash */
//#include "Lotus3_Cd6-Shamrip.h"


/* centralized modules */
#define ML_SYNTH_INLINE_DECLARATION
#include <ml_inline.h>
#undef ML_SYNTH_INLINE_DECLARATION


char shortName[] = "ML_Mod_Tracker";


static uint8_t fileIdx = 0;


/**
    @brief This function contains the setup routines.
 */
void setup(void)
{
    /*
     * this code runs once
     */
    Serial.begin(SERIAL_BAUDRATE);
    //while (!Serial);

    delay(1000);
    Serial.println(shortName);

    CapsPrintInfo();


#ifdef ML_BOARD_SETUP
    Board_Setup();
#else
    Audio_Setup();

    /*
     * setup midi module / rx port
     */
    Midi_Setup();

#ifdef MIDI_USB_ENABLED
    Midi_Usb_Setup();
#endif
#endif


#ifdef ESP32
#ifndef ESP8266 /* otherwise it will break audio output */
#ifndef ML_BOARD_SETUP
    Midi_Setup();
#endif
#endif


#endif


#ifdef BLINK_LED_PIN
    Blink_Setup();
    Blink_Fast(3);
#endif


    Serial.println();
    delay(250);

    Serial.printf("Loading data\n");


    Serial.printf("Mod Tracker Example\n");

#ifdef MAX_DELAY_Q
    /*
     * Prepare a buffer which can be used for the delay
     */
#ifdef ESP32
    static int16_t *delBuffer1 = (int16_t *)malloc(sizeof(int16_t) * MAX_DELAY_Q);
    static int16_t *delBuffer2 = (int16_t *)malloc(sizeof(int16_t) * MAX_DELAY_Q);
#else
    static int16_t delBuffer1[MAX_DELAY_Q];
    static int16_t delBuffer2[MAX_DELAY_Q];
#endif
    DelayQ_Init2(delBuffer1, delBuffer2, MAX_DELAY_Q);
#endif


    FS_Setup();


    uint32_t storageBytes = TrackerGetMemSize();

    Serial.printf("Try to allocate %" PRIu32 " bytes\n", storageBytes);


    TrackerSetup(SAMPLE_RATE);

#ifdef ARDUINO_ARCH_RP2040
    TrackerUseStaticBuffer();
#endif


#ifdef ESP32
#ifndef BOARD_HAS_PSRAM
#warning PSRAM required for this project to work
#endif
    static uint8_t *storage = (uint8_t *)ps_calloc(storageBytes, 1);

    if (storage == NULL)
    {
        Serial.printf("Not able to allocate the complete PSRAM buffer!\nNow trying to reduce the allocation buffer size...\n");

        /*
         * for some reason using a newer ESP32 board library you cannot allocate the complete PSRAM memory
         * this loop will decrease the buffer size and repeat the allocation step again until it is successful
         */
        while ((storage == NULL))
        {

        }
        Serial.printf("alloced %" PRIu32 " bytes\n", storageBytes);
    }
    TrackerSetBuffer(storage);
#endif


#ifdef ESP8266
    TrackerUseStaticBuffer();
#endif

#if 1
    /*
     * try to load the next working file
     */
    while (true)
    {
        fileIdx++;
        if (LoadFileFromIdx())
        {
            break;
        }
    }
#else
    /*
     * this is a little experiment to load static data from a file
     * to use this you need to in include a header file with
     * const uint8_t _acLotus3_Cd6_Shamrip[...] = {0x.., 0x.., ...};
     */
    TrackerLoadData(_acLotus3_Cd6_Shamrip);
#endif


    Serial.printf("setup done!\n");

    ButtonSetup(SAMPLE_RATE);

#ifdef ARDUINO_ARCH_RP2040
#ifdef TFT_CS
    DisplaySetup();
#endif
#endif

#ifdef SOC_CPU_CORES_NUM
#if SOC_CPU_CORES_NUM > 1
    Core0TaskInit();
#else
    //#error only supported by ESP32 platform
#endif
#endif
}

#ifdef SOC_CPU_CORES_NUM
#if SOC_CPU_CORES_NUM > 1
/*
 * Core 0
 */
/* this is used to add a task to core 0 */
TaskHandle_t Core0TaskHnd;


bool setup_toggle = false;

inline
void Core0TaskInit(void)
{
    /* we need a second task for the terminal output */
    xTaskCreatePinnedToCore(Core0Task, "CoreTask0", 8000, NULL, 4, &Core0TaskHnd, 0);
}

void Core0TaskSetup(void)
{
    /*
     * init your stuff for core0 here
     */
#ifdef TFT_ENABLED
    setup_lcd();
#endif

#ifdef OLED_OSC_DISP_ENABLED
    ScopeOled_Setup();
#endif
#ifdef MIDI_VIA_USB_ENABLED
    UsbMidi_Setup();
#endif
#ifdef ADC_ENABLED
    asd
    AdcSetup();
#endif
}

void Core0Cnt1Hz(void)
{
    /*
     * something happens every second here
     */
}


void Core0TaskLoop(void)
{
    /*
     * put your loop stuff for core0 here
     */
#ifdef TRACKER_PRINT_MESSAGES
    TrackerProcessOutput();
#endif

#ifdef MIDI_VIA_USB_ENABLED
    UsbMidi_Loop();
#endif

#ifdef OLED_OSC_DISP_ENABLED
    ScopeOled_Process();
#endif
}

void Core0Task(void *parameter)
{
    Core0TaskSetup();

    while (true)
    {
        Core0TaskLoop();

        /* this seems necessary to trigger the watchdog */
        delay(1);
        yield();
    }
}
#endif /* SOC_CPU_CORES_NUM>1 */
#endif /* SOC_CPU_CORES_NUM */

#ifdef ARDUINO_ARCH_RP2040
void setup1()
{
    delay(3000);
    Serial.printf("setup1 done\n");
    printf("Enter loop1...\n");

    // ButtonSetup(F_CPU);
}

void loop1()
{
    uint32_t clr[64];

    TrackerGetClr(clr);
    // ButtonProcess(1250000);

    TrackerProcessOutput();
    delay(40);
}
#endif /* ARDUINO_ARCH_RP2040 */

/**
    @brief This function will be called every second.
        In case of an overload the function will not called so often
  */
void loop_1Hz(void)
{
#ifdef BLINK_LED_PIN
    Blink_Process();
#endif
}


float inputGain = 1.0f;

void ScaleLfo(const float *in, float *out, uint32_t len, float minV, float maxV)
{
    for (uint32_t n = 0; n < len; n++)
    {
        float maxF, minF;
        maxF = (1.0f + in[n]) * 0.5f;
        minF = 1.0f - maxF;
        out[n] = minF * minV + maxF * maxV;
    }
}

void Tracker_Autostart()
{
    static uint8_t titleIdx = 5;

    if (Tracker_HasTrackFinished() == true)
    {
        switch (titleIdx)
        {
        case 0:
            if (FS_OpenFile(FS_ID_LITTLEFS, "/house_my_kolsch_up.mod"))
            {
                if (TrackerLoadFile())
                {
                    TrackerStartPlayback();
                }
            }
            break;

        case 1:
            if (FS_OpenFile(FS_ID_LITTLEFS, "/MONSTER.MOD"))
            {
                if (TrackerLoadFile())
                {
                    TrackerStartPlayback();
                }
            }
            break;

        case 2:
            if (FS_OpenFile(FS_ID_LITTLEFS, "/Lotus3_Cd6-Shamrip.mod"))
            {
                if (TrackerLoadFile())
                {
                    TrackerStartPlayback();
                }
            }
            break;

        case 3:
            if (FS_OpenFile(FS_ID_LITTLEFS, "/MINES.MOD"))
            {
                if (TrackerLoadFile())
                {
                    TrackerStartPlayback();
                }
            }
            break;

        case 4:
            if (FS_OpenFile(FS_ID_LITTLEFS, "/2unlimitedmagic.mod"))
            {
                if (TrackerLoadFile())
                {
                    TrackerStartPlayback();
                }
            }
            break;

        case 5:
            if (FS_OpenFile(FS_ID_LITTLEFS, "/PRES.MOD"))
            {
                if (TrackerLoadFile())
                {
                    TrackerStartPlayback();
                }
            }
            break;

        case 6:
            if (FS_OpenFile(FS_ID_LITTLEFS, "/PRES.MOD"))
            {
                if (TrackerLoadFile())
                {
                    TrackerStartPlayback();
                }
            }
            break;

        case 7:
            if (FS_OpenFile(FS_ID_LITTLEFS, "/Lotus3_Cd3-Lotus3.mod"))
            {
                if (TrackerLoadFile())
                {
                    TrackerStartPlayback();
                }
            }
            break;
#if 0
        case 9:
            if (FS_OpenFile(FS_ID_LITTLEFS, "/MICMAC2-TITLE.mod"))
            {
                if (TrackerLoadFile())
                {
                    TrackerStartPlayback();
                }
            }
            break;
#endif
        case 8:
            if (FS_OpenFile(FS_ID_LITTLEFS, "/Lotus3_Cd1-Breathless.mod"))
            {
                if (TrackerLoadFile())
                {
                    TrackerStartPlayback();
                }
            }
            break;
        }

        titleIdx ++;

    }
}

/**
    @brief This function contains the mainloop
 */
void loop(void)
{
    static int loop_cnt_1hz = 0; /*!< counter to allow 1Hz loop cycle */

#ifdef SAMPLE_BUFFER_SIZE
    loop_cnt_1hz += SAMPLE_BUFFER_SIZE;
#else
    loop_cnt_1hz += 1; /* in case only one sample will be processed per loop cycle */
#endif

    if (loop_cnt_1hz >= SAMPLE_RATE)
    {
        loop_cnt_1hz -= SAMPLE_RATE;
        loop_1Hz();
    }

    ButtonProcess(SAMPLE_BUFFER_SIZE);

    /*
     * loading next file when tracker stops playing
     */
    Tracker_Autostart();

    /*
     * MIDI processing
     */
    Midi_Process();

#ifdef MIDI_VIA_USB_ENABLED
    UsbMidi_ProcessSync();
#endif

#ifdef MIDI_STREAM_PLAYER_ENABLED
    MidiStreamPlayer_Tick(SAMPLE_BUFFER_SIZE);
#endif

#ifdef MIDI_BLE_ENABLED
    midi_ble_loop();
#endif

#ifdef USB_HOST_ENABLED
    Usb_Host_Midi_loop();
#endif

#ifdef MIDI_USB_ENABLED
    Midi_Usb_Loop();
#endif

    /*
     * Handle status messages
     */
    //Status_Loop(SAMPLE_BUFFER_SIZE);
    Status_Loop(240000);
    Status_LoopMain();

    /*
     * And finally the audio stuff
     */
    Q1_14 left[SAMPLE_BUFFER_SIZE], right[SAMPLE_BUFFER_SIZE];

    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));


#ifdef AUDIO_PASS_THROUGH
    Audio_Input(left, right);

    mul(left, inputGain, left, SAMPLE_BUFFER_SIZE);
    mul(right, inputGain, right, SAMPLE_BUFFER_SIZE);
#endif

    TrackerProcessSamples(left, right, SAMPLE_BUFFER_SIZE);

#ifdef MAX_DELAY_Q
    /*
     * post process delay
     */
    DelayQ_Process_Buff(&left[0].s16, &right[0].s16, &left[0].s16, &right[0].s16, SAMPLE_BUFFER_SIZE);
#endif


    /* ~21dB margin required to allow playing all notes at the same time -> overdrive would help */

    /*
     * Output the audio
     */
    Audio_Output(left, right);

#ifdef OLED_OSC_DISP_ENABLED
    {
        float fl_sample[SAMPLE_BUFFER_SIZE];
        float fr_sample[SAMPLE_BUFFER_SIZE];
        const float convf = 1.0f / 16384.0f;
        for (uint32_t n = 0; n < SAMPLE_BUFFER_SIZE; n++)
        {
            fl_sample[n] = ((float)left[n].s16) * convf;
            fr_sample[n] = ((float)right[n].s16) * convf;
        }
        ScopeOled_AddSamples(fl_sample, fr_sample, SAMPLE_BUFFER_SIZE);
    }
#endif
}


void GenerateSilence(void)
{
    Q1_14 left[SAMPLE_BUFFER_SIZE], right[SAMPLE_BUFFER_SIZE];

    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
#ifdef AUDIO_4CH_ENABLED
    Audio_Output(left, right, left, right);
    Audio_Output(left, right, left, right);
#else
    Audio_Output(left, right);
    Audio_Output(left, right);
#endif
}

bool LoadFileFromIdx(void)
{
    GenerateSilence();

    char filename[64];
    char filter[] = ".mod";

    if (getFileFromIdx(fileIdx, filename, filter) == false)
    {
        fileIdx = 0;
        getFileFromIdx(fileIdx, filename, filter);
    }

    if (FS_OpenFile(FS_ID_LITTLEFS, filename))
    {
        Serial.printf("File opened: %s\n", filename);

        if (TrackerLoadFile())
        {
            Serial.printf("File loaded into tracker\n");
            FS_CloseFile();
            TrackerStartPlayback();
            return true;
        }
        else
        {
            Serial.printf("Unable to load file\n");
        }
        FS_CloseFile();
    }
    return false;
}

void LoadFileNext(void)
{
    while (true)
    {
        fileIdx++;
        if (LoadFileFromIdx())
        {
            break;
        }
    }
}

void LoadFilePrev(void)
{
    while (true)
    {
        fileIdx--;
        if (LoadFileFromIdx())
        {
            break;
        }
    }
}

/*
 * MIDI callbacks
 */
inline void AppBtn(uint8_t param, uint8_t value)
{
    if (value > 0)
    {
        switch (param)
        {
#ifdef AC101_ENABLED
        case 0:
            ac101_setSourceMic();
            break;
        case 1:
            ac101_setSourceLine();
            break;
#endif

        case 4:
            LoadFileNext();
            break;

        case 5:
            LoadFilePrev();
            break;

        default:
            break;
        }
    }
}

void AppSetInputGain(uint8_t unused __attribute__((unused)), uint8_t value)
{
    inputGain = log2fromU7(value, -16, 5);
    Status_ValueChangedFloat("Input", "Gain", inputGain);
}

/**
 * @brief
 *
 * @param unused
 * @param value
 */
#ifdef MAX_DELAY_Q
void App_DelayQ_SetLength(uint8_t unused __attribute__((unused)), uint8_t value)
{
    uint32_t val32 = value;
    val32 *= 189;
    DelayQ_SetLength(unused, val32);
}
#endif
