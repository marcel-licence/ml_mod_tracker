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
 * include the board configuration
 * there you will find the most hardware depending pin settings
 */
#include <ml_boards.h> /* requires the ML_Synth library:  https://github.com/marcel-licence/ML_SynthTools */


#endif /* CONFIG_H_ */
