/*
 * Copyright (c) 2026 Marcel Licence
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
 * @file config.h
 * @author Marcel Licence
 * @date 13.03.2024
 *
 * @brief You will find the project configuration settings in this file
 */


#ifdef __CDT_PARSER__
#include <cdt.h>
#endif


#ifndef CONFIG_H_
#define CONFIG_H_


/*
 * use the following to print the tracker message
 * It might slow down the audio
 */
//#define TRACKER_PRINT_MESSAGES

/*
 * include simple status module
 */
#define STATUS_SIMPLE

#ifdef TEENSYDUINO
#include <Audio.h> /* required to access teensy audio defines */
#endif

/*
 * sample / audio settings for all platforms
 */
#define SAMPLE_BUFFER_SIZE  48
#define SAMPLE_RATE 48000
#define SAMPLE_SIZE_16BIT

/*
 * use the following define to test the output of the codec
 */
//#define OUTPUT_SAW_TEST

/*
 * serial settings
 */
#define SERIAL_BAUDRATE 115200


#define MIDI_FMT_INT


/*
 * Configuration for
 * Board: "LOLIN(WEMOS) D1 R2 & mini 2 or similar
 */
#ifdef ESP8266
#define ESP8266AUDIO_I2SNODAC_LIB
#ifdef LED_BUILTIN
#define BLINK_LED_PIN LED_BUILTIN
#else
#define BLINK_LED_PIN D4
#endif

#define BUTTON_STARTSTOP_PIN    D5
#define BUTTON_NEXT_PIN D6
#define BUTTON_RESTART_PIN  D7
#define BUTTON_STEP_PIN  D8

#define BUTTON_NEXT_GND_PIN D3
#endif


#if (defined ESP32) && (!defined ARDUINO_LOLIN_S2_MINI) && (!defined ARDUINO_ESP32S2_DEV) && (!defined ARDUINO_ESP32C3_DEV) && (!defined ARDUINO_SEEED_XIAO_M0)

#define BOARD_ESP32_AUDIO_KIT_ES8388
//#define AUDIO_PASS_THROUGH
#define MAX_DELAY_Q 12000

#define BUTTON_STARTSTOP_PIN    12
#define BUTTON_NEXT_PIN 13
#define BUTTON_RESTART_PIN  14
#define BUTTON_STEP_PIN  15

#ifdef SOC_CPU_HAS_FPU
#define REVERB_ENABLED
#endif /* SOC_CPU_HAS_FPU */
#endif


#include <ml_boards.h>


/*
 * Configuration for the Lolin S2 Mini
 * Should work with other ESP32-S2 devices too
 */
#if (defined ARDUINO_LOLIN_S2_MINI) || (defined ARDUINO_ESP32S2_DEV)
#define I2S_BCLK_PIN -1
#define I2S_WCLK_PIN -1
#define I2S_DOUT_PIN 17
#define I2S_DIRECT_OUT
#define BLINK_LED_PIN   15

#define BUTTON_STARTSTOP_PIN    12
#define BUTTON_NEXT_PIN 13
#define BUTTON_RESTART_PIN  14
#define BUTTON_STEP_PIN  5

//#define BUTTON_NEXT_PIN 12
#define BUTTON_NEXT_GND_PIN 11
#endif /* (defined ARDUINO_LOLIN_S2_MINI) || (defined ARDUINO_ESP32S2_DEV)  */

/*
 * Configuration for
 * Board: "Teensy 4.1"
 *
 * BCK: 21
 * DIN: 7
 * LCK: 20
 */
#ifdef TEENSYDUINO // CORE_TEENSY

#define BLINK_LED_PIN 13 /* led pin on teensy 4.1 */
#define MIDI_PORT1_ACTIVE
#define MIDI_SERIAL1_BAUDRATE   31250
#define SAMPLE_BUFFER_SIZE AUDIO_BLOCK_SAMPLES
#define SAMPLE_RATE AUDIO_SAMPLE_RATE
#define VOLUME_CONTROL_ENABLED
//#define VIBRATO_ENABLED

#endif /* TEENSYDUINO */


/*
 * Configuration for
 * Board: "Generic STM32F4 Series"
 * Board part number: "BlackPill F411CE"
 */
#ifdef ARDUINO_BLACKPILL_F411CE

#define LED_PIN LED_BUILTIN
#define SAMPLE_BUFFER_SIZE  48
#define SAMPLE_RATE 48000

#define MIDI_PORT1_ACTIVE
#define MIDI_BAUDRATE   31250

#endif /* ARDUINO_BLACKPILL_F411CE */


/*
 * Configuration for
 * Board: "Generic STM32H7 Series"
 * Board part number: "Daisy Seed"
 */
#ifdef ARDUINO_DAISY_SEED

#define LED_PIN LED_BUILTIN
#define SAMPLE_BUFFER_SIZE  48
#define SAMPLE_RATE 48000

#define MIDI_PORT2_ACTIVE
#define MIDI_BAUDRATE   31250

#endif /* ARDUINO_DAISY_SEED */

/*
 * Configuration for
 * Board: "Seeeduino XIAO"
 */
#if (defined ARDUINO_SEEED_XIAO_M0) || (defined SEEED_XIAO_M0)

#define BLINK_LED_PIN LED_BUILTIN
#define SAMPLE_BUFFER_SIZE  48
#define SAMPLE_RATE  22050

#define MIDI_PORT1_ACTIVE

#endif /* (defined ARDUINO_SEEED_XIAO_M0) || (defined SEEED_XIAO_M0) */

/*
 * Configuration for
 * Board: "Rapsberry Pi Pico"
 *
 * BCK: 26
 * DIN: 28
 * LCK: 27  (always BCK + 1)
 *
 * MIDI_RX: 12 (GP9)
 *
 * Pinout @see https://www.raspberrypi-spy.co.uk/2021/01/pi-pico-pinout-and-power-pins/#prettyPhoto
 */
#if (defined ARDUINO_RASPBERRY_PI_PICO) || (defined ARDUINO_ARCH_RP2040)
#ifndef __ARM_FEATURE_DSP
#define BLINK_LED_PIN 25
#define WS2812_PIN  28

#define RP2040_AUDIO_PWM
#define MAX_DELAY_Q 8096
#define BUTTON_STARTSTOP_PIN    16
#define BUTTON_NEXT_PIN 20
#define BUTTON_RESTART_PIN  26
#define BUTTON_STEP_PIN  15
#define BUTTON_OTHER1_PIN  11
#define BUTTON_OTHER2_PIN  7
#endif
#endif


/*
 * configuration for the Raspberry Pi Pico 2
 * BOARD: Raspberry Pi RP2040 (4.0.1)
 * Device: Raspberry Pi Pico 2
 */
#ifdef ARDUINO_ARCH_RP2040
#ifdef __ARM_FEATURE_DSP
//#define MAX_DELAY_Q 8096
#define PICO_AUDIO_I2S
#define PICO_AUDIO_I2S_DATA_PIN 26
#define PICO_AUDIO_I2S_CLOCK_PIN_BASE 27
#define MIDI_RX1_PIN    13
#define MIDI_TX1_PIN    12
#define LED_PIN LED_BUILTIN
#define BLINK_LED_PIN LED_BUILTIN
#define WS2812_PIN 3
#endif
#endif


/*
 * Configuration for
 * Board: "Generic STM32F4 Series"
 * Board part number: "Generic F407VGTx"
 *
 * does not work at the moment
 */
#ifdef ARDUINO_GENERIC_F407VGTX

#include <ml_boards.h> /* requires the ML_Synth library:  https://github.com/marcel-licence/ML_SynthTools */

#define BLINK_LED_PIN LED_USER_RED
#define LED_PIN LED_USER_GREEN

#define SAMPLE_BUFFER_SIZE  48
#define SAMPLE_RATE  44100

#define MIDI_PORT2_ACTIVE

#endif /* ARDUINO_GENERIC_F407VGTX */


#ifdef ARDUINO_DISCO_F407VG

/*
 * pro organ seems not to work. Maybe too slow?
 */

#include <ml_boards.h> /* requires the ML_Synth library:  https://github.com/marcel-licence/ML_SynthTools */

#define BLINK_LED_PIN LED_USER_RED
#define LED_PIN LED_USER_GREEN

#define SAMPLE_BUFFER_SIZE  48
#define SAMPLE_RATE  48000

//#define MIDI_PORT1_ACTIVE /* MIDI in : PIN A10  not tested*/
#define MIDI_PORT2_ACTIVE /* MIDI in : PIN A3 */

#endif /* ARDUINO_DISCO_F407VG */


#ifdef ARDUINO_BLACK_F407VE
/*
 * from variant.h
 * LED_BUILTIN: PA6
 * LED1_BUILTIN: PA7
 *
 * USER_BUTTON0: PA0
 * USER_BUTTON1: PE3
 * USER_BUTTON2: PE4
 *
 * SDA: PB7
 * SCL: PB6
 *
 * @see http://wiki.stm32duino.com/images/5/5c/STM32_F4VE_SCHEMATIC.PDF
 */
#define BLINK_LED_PIN LED_BUILTIN /* PA6 */
#define LED_PIN LED_BUILTIN

#define SAMPLE_BUFFER_SIZE  48
#define SAMPLE_RATE  44100

/*
 * define your I2S interface here!
 * values are just example values and will not work
 */
#define I2S_I2SN    SPI1 // Using SPI1 for I2S
#define I2S_MCLK    PC7 // I2S1_MCK
#define I2S_SCLK    PC10 // I2S1_CK
#define I2S_SDIN    PC12 // I2S1_SD mcu out -> dac in
#define I2S_LRCK    PA4 // I2S1_WS

#endif /* DARDUINO_BLACK_F407VE */


#ifdef ARDUINO_BLUEPILL_F103C8

#define BLINK_LED_PIN LED_BUILTIN
#define LED_PIN LED_BUILTIN

#define SAMPLE_BUFFER_SIZE  48
#define SAMPLE_RATE  44100

/*
 * define your I2S interface here!
 * values are just example values and will not work
 */
#define I2S_I2SN    SPI1 // Using SPI1 for I2S
#define I2S_MCLK    PB7 // I2S1_MCK
#define I2S_SCLK    PC15 // I2S1_CK
#define I2S_SDIN    PC9 // I2S1_SD mcu out -> dac in
#define I2S_LRCK    PA4 // I2S1_WS

#endif /* ARDUINO_BLUEPILL_F103C8 */


#ifdef ARDUINO_BLUE_F103VE

#define BLINK_LED_PIN LED_BUILTIN
#define LED_PIN LED_BUILTIN

#define SAMPLE_BUFFER_SIZE  48
#define SAMPLE_RATE  44100

/*
 * define your I2S interface here!
 * values are just example values and will not work
 */
#define I2S_I2SN    SPI1 // Using SPI1 for I2S
#define I2S_MCLK    PC7 // I2S1_MCK
#define I2S_SCLK    PC10 // I2S1_CK
#define I2S_SDIN    PC12 // I2S1_SD mcu out -> dac in
#define I2S_LRCK    PA4 // I2S1_WS

#endif /* ARDUINO_BLUE_F103VE */


#endif /* CONFIG_H_ */
