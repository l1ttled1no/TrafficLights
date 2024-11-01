/*
 * input_reading.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */


#include "main.h"

// We aim to work with more than one button
#define NO_OF_BUTTONS 3

// Timer interrupt duration is 10ms, so to pass 1 second,
// we need to jump to the interrupt service routine 100 times
#define DURATION_FOR_AUTO_INCREASING 100

#define BUTTON_IS_PRESSED GPIO_PIN_RESET
#define BUTTON_IS_RELEASED GPIO_PIN_SET

// The buffer that the final result is stored after debouncing
static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];

// We define two buffers for debouncing
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];

// We define a flag for a button pressed more than 1 second
static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];

// We define counter for automatically increasing the value
// after the button is pressed more than 1 second
static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];

void button_reading(void) {
    for (char i = 0; i < NO_OF_BUTTONS; i++) {
        debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
        switch (i) {
            case 0:
                debounceButtonBuffer1[i] =HAL_GPIO_ReadPin(L_BUTTON_GPIO_Port, L_BUTTON_Pin);
                break;
            case 1:
                debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(N_BUTTON_GPIO_Port, N_BUTTON_Pin);
                break;
            case 2:
                debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(Y_BUTTON_GPIO_Port, Y_BUTTON_Pin);
                break;
        }

        if (debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
            buttonBuffer[i] = debounceButtonBuffer1[i];

        if (buttonBuffer[i] == BUTTON_IS_PRESSED) {
            // If a button is pressed, we start counting
            if (counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING) {
                counterForButtonPress1s[i]++;
            } else {
                // The flag is turned on when 1 second has passed
                // since the button is pressed
                flagForButtonPress1s[i] = 1;
                // TODO
            }
        } else {
            counterForButtonPress1s[i] = 0;
            flagForButtonPress1s[i] = 0;
        }
    }
}

unsigned char is_button_pressed(uint8_t index) {
    if (index >= NO_OF_BUTTONS) return 0;
    return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

unsigned char is_button_pressed_1s(unsigned char index) {
    if (index >= NO_OF_BUTTONS) return 0xff;
    return (flagForButtonPress1s[index] == 1);
}
