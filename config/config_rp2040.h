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
 * @file config_rp2040.h
 * @author Marcel Licence
 *
 * @brief Configuration for
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

#if (defined ARDUINO_ARCH_RP2040) && (!defined __ARM_FEATURE_DSP)


#define WS2812_PIN  28
#define MAX_DELAY_Q 8096

#ifdef ARDUINO_RASPBERRY_PI_PICO
#define BLINK_LED_PIN LED_BUILTIN
#else
#define BLINK_LED_PIN 19
#endif


#define BUTTON_STARTSTOP_PIN    16
#define BUTTON_NEXT_PIN 20
#define BUTTON_RESTART_PIN  26
#define BUTTON_STEP_PIN  15
#define BUTTON_OTHER1_PIN  11
#define BUTTON_OTHER2_PIN  7


#if 1
#define RP2040_AUDIO_PWM
#else
#define PICO_AUDIO_I2S
#define PICO_AUDIO_I2S_DATA_PIN 26
#define PICO_AUDIO_I2S_CLOCK_PIN_BASE 27
#endif


#endif /* (defined ARDUINO_ARCH_RP2040) && (!defined __ARM_FEATURE_DSP) */
