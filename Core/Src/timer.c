/*
 * timer.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#include "main.h"
#include "input_reading.h"
#include "software_timer.h"
#include "button.h"

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef * htim)
{
    timer_run();
    getKeyInput();
}
