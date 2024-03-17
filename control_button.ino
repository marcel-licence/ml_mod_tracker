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
 * @file control_button.ino
 * @author Marcel Licence
 * @date 25.02.2024
 *
 * @brief In this file button presses are detected and controls the tracker
 */


#define BUTTON_STARTSTOP    0
#define BUTTON_NEXT    1
#define BUTTON_RESTART    2
#define BUTTON_STEP    3


static uint32_t button_sample_rate = 0;

struct buttons_s
{
    int pin;
    uint32_t function;
    uint32_t holdtime;
    bool pressed;
};

static struct buttons_s buttons[] =
{
#ifdef BUTTON_STARTSTOP_PIN
    {BUTTON_STARTSTOP_PIN, BUTTON_STARTSTOP, 0, false},
#endif
#ifdef BUTTON_NEXT_PIN
    {BUTTON_NEXT_PIN, BUTTON_NEXT, 0, false},
#endif
#ifdef BUTTON_RESTART_PIN
    {BUTTON_RESTART_PIN, BUTTON_RESTART, 0, false},
#endif
#ifdef BUTTON_STEP_PIN
    {BUTTON_STEP_PIN, BUTTON_STEP, 0, false},
#endif
};

void ButtonSetup(uint32_t sample_rate)
{
    button_sample_rate = sample_rate;

    for (uint32_t n = 0; n < sizeof(buttons) / sizeof(buttons[0]); n++)
    {
        pinMode(buttons[n].pin, INPUT_PULLUP);
        buttons[n].pressed = false;
    }

#ifdef BUTTON_NEXT_GND_PIN
    pinMode(BUTTON_NEXT_GND_PIN, OUTPUT);
    digitalWrite(BUTTON_NEXT_GND_PIN, LOW);
#endif
}

void ButtonPress(uint32_t function)
{
    switch (function)
    {
    case BUTTON_STARTSTOP:
        Tracker_Start(0, 127);
        break;
    case BUTTON_NEXT:
        LoadFileNext();
        break;
    case BUTTON_RESTART:
        Tracker_Restart(0, 127);
        break;
    case BUTTON_STEP:
        Tracker_Step(1, 127);
        break;
    }
}

void ButtonProcess(uint32_t ticks)
{
    for (uint32_t n = 0; n < sizeof(buttons) / sizeof(buttons[0]); n++)
    {
        if (digitalRead(buttons[n].pin) == LOW)
        {
            if (buttons[n].holdtime < button_sample_rate / 16)
            {
                if (buttons[n].holdtime + ticks >= button_sample_rate / 16)
                {
                    if (buttons[n].pressed == false)
                    {
                        ButtonPress(buttons[n].function);
                        buttons[n].pressed = true;
                    }
                }
                buttons[n].holdtime += ticks;
            }
        }
        else
        {
            buttons[n].holdtime = 0;
            buttons[n].pressed = false;
        }
    }
}
