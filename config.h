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


#ifdef ESP32
#ifndef ARDUINO_LOLIN_S2_MINI
#define BOARD_ESP32_AUDIO_KIT_ES8388
//#define AUDIO_PASS_THROUGH
#define MAX_DELAY_Q 12000

#define BUTTON_STARTSTOP_PIN    12
#define BUTTON_NEXT_PIN 13
#define BUTTON_RESTART_PIN  14
#define BUTTON_STEP_PIN  15

#ifdef SOC_CPU_HAS_FPU
#define REVERB_ENABLED
#endif
#endif
#endif


#include <ml_boards.h>


#if (defined ARDUINO_RASPBERRY_PI_PICO) || (defined ARDUINO_ARCH_RP2040)
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

/*
 * Configuration for the Lolin S2 Mini
 * Should work with other ESP32-S2 devices too
 */
#ifdef ARDUINO_LOLIN_S2_MINI
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
#endif

/*
 * Configuration for the ESP8266
 * tested with the d1-mini
 */
#ifdef ESP8266
#define ESP8266AUDIO_I2SNODAC_LIB
#define BLINK_LED_PIN D4

#define BUTTON_STARTSTOP_PIN    D5
#define BUTTON_NEXT_PIN D6
#define BUTTON_RESTART_PIN  D7
#define BUTTON_STEP_PIN  D8

#define BUTTON_NEXT_GND_PIN D3
#endif


#endif /* CONFIG_H_ */
