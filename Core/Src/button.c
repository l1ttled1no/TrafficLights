#include "button.h"

#define NUM_BUTTONS 3

int KeyReg0[NUM_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[NUM_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[NUM_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg3[NUM_BUTTONS] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int TimeOutForKeyPress[NUM_BUTTONS] = {50, 50, 50};
int button_pressed[NUM_BUTTONS] = {0, 0, 0};
int button_long_pressed[NUM_BUTTONS] = {0, 0, 0};
int button_flag[NUM_BUTTONS] = {0, 0, 0};

int isButtonPressed(int index){
    if(button_flag[index] == 1){
        button_flag[index] = 0;
        return 1;
    }
    return 0;
}

int isButtonLongPressed(int index){
    if(button_long_pressed[index] == 1){
        button_long_pressed[index] = 0;
        return 1;
    }
    return 0;
}

void subKeyProcess(int index){
    //TODO
    //HAL_GPIO_TogglePin(PA5_GPIO_Port, PA5_Pin);
    button_flag[index] = 1;
}



void getKeyInput(){
    for(int i = 0; i < NUM_BUTTONS; i++){
    	KeyReg2[i] = KeyReg1[i];
    	KeyReg1[i] = KeyReg0[i];
        // Add your key
        switch(i){
            case 0:
                KeyReg0[i] = HAL_GPIO_ReadPin(L_BUTTON_GPIO_Port, L_BUTTON_Pin);
                break;
            case 1:
                KeyReg0[i] = HAL_GPIO_ReadPin(N_BUTTON_GPIO_Port, N_BUTTON_Pin);
                break;
            case 2:
                KeyReg0[i] = HAL_GPIO_ReadPin(Y_BUTTON_GPIO_Port, Y_BUTTON_Pin);
                break;
        }

        if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
            if (KeyReg2[i] != KeyReg3[i]){
                KeyReg3[i] = KeyReg2[i];

                if (KeyReg0[i] == PRESSED_STATE){
                    TimeOutForKeyPress[i] = 100;
                    //forfun(i);
                    button_flag[i] = 1;
                }
            }else{
                TimeOutForKeyPress[i]--;
                if (TimeOutForKeyPress[i] == 0){
                    TimeOutForKeyPress[i] = 10;
                    if (KeyReg3[i] == PRESSED_STATE){
                        //subKeyProcess(i);
                        button_flag[i] = 1;
                    }
                }
            }
        }
    }
}
