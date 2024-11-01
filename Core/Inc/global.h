/*
 * global.h
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "input_reading.h"
#include "software_timer.h"
#include "button.h"

#define INIT 				1
#define NS_GREEN_EW_RED		2
#define NS_YELLOW_EW_RED	3
#define NS_RED_EW_GREEN		4
#define NS_RED_EW_YELLOW	5

#define MAN_RED		12
#define MAN_YELLOW 	13
#define MAN_GREEN	14

#define SEG_01 0
#define SEG_23 1


extern int traffic_status;
extern int segment_status;
extern int status;

extern int segment_buffer[4];
extern int ns_time_left;
extern int ew_time_left;

extern int temp_red;
extern int temp_green;
extern int temp_yellow;

void display7SEG(int num);
void update7SEG(int index);


#endif /* INC_GLOBAL_H_ */
