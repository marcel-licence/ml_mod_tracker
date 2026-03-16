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
 * @file config_esp32.h
 * @author Marcel Licence
 *
 * @brief Configuration for ESP32
 */

#if (defined ESP32) && (!defined ARDUINO_LOLIN_S2_MINI) && (!defined ARDUINO_ESP32S2_DEV) && (!defined ARDUINO_ESP32C3_DEV) && (!defined ARDUINO_SEEED_XIAO_M0)

// #define BOARD_ML_V1 /* activate this when using the ML PCB V1 */
//#define BOARD_ML_SYNTH_V2 /* activate this when using the ML PCB V2 */
#define BOARD_ESP32_AUDIO_KIT_AC101 /* activate this when using the ESP32 Audio Kit v2.2 with the AC101 codec */
//#define BOARD_ESP32_AUDIO_KIT_ES8388 /* activate this when using the ESP32 Audio Kit v2.2 with the ES8388 codec */
//#define BOARD_ESP32_DOIT /* activate this when using the DOIT ESP32 DEVKIT V1 board */
//#define BOARD_WEMOS_D1_MINI_ESP32
//#define I2S_NODAC
//#define INPUT_TO_MIX /* use this to mix the input to the organ signal */

//#define AUDIO_PASS_THROUGH
#define MAX_DELAY_Q 12000

#define BUTTON_STARTSTOP_PIN    12
#define BUTTON_NEXT_PIN 13
#define BUTTON_RESTART_PIN  14
#define BUTTON_STEP_PIN  15

#ifdef SOC_CPU_HAS_FPU
#define REVERB_ENABLED
#endif /* SOC_CPU_HAS_FPU */


#endif /* (defined ESP32) && (!defined ARDUINO_LOLIN_S2_MINI) && (!defined ARDUINO_ESP32S2_DEV) && (!defined ARDUINO_ESP32C3_DEV) && (!defined ARDUINO_SEEED_XIAO_M0) */

