/*
 * software_timer.h
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define CLOCK_PERIOD  10

extern int timer1_counter;
extern int timer2_counter;
extern int timer3_counter;
extern int timer4_counter;

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timer4_flag;

void setTimer_1(int duration);
void setTimer_2(int duration);
void setTimer_3(int duration);
void setTimer_4(int duration);

void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
