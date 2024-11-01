#include "fsm.automatic.h"

#define red_light 	69
#define yel_light	72
#define grn_light	12
int red_duration = 5;
int green_duration = 3;
int yellow_duration = 2;

int red_flag = 0,
	grn_flag = 0,
	yel_flag = 0;

int temp_red = 1;
int temp_green = 1;
int temp_yellow = 1;

// LED display counters
int led1 = 0;
int led2 = 0;

// Timer for state transitions
int timer;

int status = INIT;
int traffic_status = INIT;
int segment_status = SEG_01;
int ns_time_left = 0;
int ew_time_left = 0;
int segment_buffer[4];

int forfun;

int led_index = 0;

//void set_lights(int red, int yellow, int green, GPIO_TypeDef* port, uint16_t red_pin, uint16_t yellow_pin, uint16_t green_pin) {
//    HAL_GPIO_WritePin(port, red_pin, red ? 1 : 0);
//    HAL_GPIO_WritePin(port, yellow_pin, yellow ? 1 : 0);
//    HAL_GPIO_WritePin(port, green_pin, green ? 1 : 0);
//}

void setLightH(int choice){
	switch (choice){
	case red_light:
	{
		HAL_GPIO_WritePin(HA_GPIO_Port, HA_Pin, 1);
		HAL_GPIO_WritePin(HB_GPIO_Port, HB_Pin, 1);
		red_flag = 1;
		grn_flag = 0;
		yel_flag = 0;
		break;
	}
	case yel_light:
	{
		HAL_GPIO_WritePin(HA_GPIO_Port, HA_Pin, 0);
		HAL_GPIO_WritePin(HB_GPIO_Port, HB_Pin, 1);
		red_flag = 0;
		grn_flag = 0;
		yel_flag = 1;
		break;
	}
	case grn_light:
	{
		HAL_GPIO_WritePin(HA_GPIO_Port, HA_Pin, 1);
		HAL_GPIO_WritePin(HB_GPIO_Port, HB_Pin, 0);
		red_flag = 0;
		grn_flag = 1;
		yel_flag = 0;
		break;
	}
	default:
	{
		HAL_GPIO_WritePin(HA_GPIO_Port, HA_Pin, 0);
		HAL_GPIO_WritePin(HB_GPIO_Port, HB_Pin, 0);
		red_flag = 0;
		grn_flag = 0;
		yel_flag = 0;
		break;
	}
	}
}

void setLightV(int choice){
	switch (choice){
	case red_light:
	{
		HAL_GPIO_WritePin(VA_GPIO_Port, VA_Pin, 1);
		HAL_GPIO_WritePin(VB_GPIO_Port, VB_Pin, 1);
		red_flag = 1;
				grn_flag = 0;
				yel_flag = 0;
		break;
	}
	case yel_light:
	{
		HAL_GPIO_WritePin(VA_GPIO_Port, VA_Pin, 0);
		HAL_GPIO_WritePin(VB_GPIO_Port, VB_Pin, 1);
		red_flag = 0;
				grn_flag = 0;
				yel_flag = 1;
		break;
	}
	case grn_light:
	{
		HAL_GPIO_WritePin(VA_GPIO_Port, VA_Pin, 1);
		HAL_GPIO_WritePin(VB_GPIO_Port, VB_Pin, 0);
		red_flag = 0;
				grn_flag = 1;
				yel_flag = 0;
		break;
	}
	default:
	{
		HAL_GPIO_WritePin(VA_GPIO_Port, VA_Pin, 0);
		HAL_GPIO_WritePin(VB_GPIO_Port, VB_Pin, 0);
		red_flag = 0;
				grn_flag = 0;
				yel_flag = 0;
		break;
	}
	}
}

void updateLED(){
	segment_buffer[0] = led1/10; //dozen
	segment_buffer[1] = led1%10; //digit
	segment_buffer[2] = led2/10;
	segment_buffer[3] = led2%10;
}

void auto_traffic(){
	//updateLED();
	lcd_clear_display();
	//int forfun = 1;
	switch(traffic_status){
    case INIT:
      	ns_time_left = green_duration;
    	ew_time_left = red_duration;
    	timer = green_duration;
    	traffic_status = NS_GREEN_EW_RED;
    	//forfun = 0;
    	break;
    case NS_GREEN_EW_RED:
    	setLightV(grn_light);
    	setLightH(red_light);

    	lcd_goto_XY(1, 0);
    	lcd_send_string("Green");
    	lcd_goto_XY(2, 0);
    	lcd_send_string("Red");

		lcd_goto_XY(1, 8);
		lcd_print_int(ns_time_left);
		lcd_goto_XY(2, 8);
		lcd_print_int(ew_time_left);

        if (timer == 0) {
            traffic_status = NS_YELLOW_EW_RED;
            ns_time_left = yellow_duration;
            timer = yellow_duration;
        }
        break;
    case NS_YELLOW_EW_RED:
    	setLightV(yel_light);
    	setLightH(red_light);

    	lcd_goto_XY(1, 0);
    	lcd_send_string("Yellow");
    	lcd_goto_XY(2, 0);
    	lcd_send_string("Red");

		lcd_goto_XY(1, 8);
		lcd_print_int(ns_time_left);
		lcd_goto_XY(2, 8);
		lcd_print_int(ew_time_left);

    	if (timer ==0){
    		traffic_status = NS_RED_EW_GREEN;
    		ns_time_left = red_duration;
    		ew_time_left = green_duration;
    		timer = green_duration;
    	}
    	break;
	case NS_RED_EW_GREEN:
		setLightV(red_light);
		setLightH(grn_light);

    	lcd_goto_XY(1, 0);
    	lcd_send_string("Red");
    	lcd_goto_XY(2, 0);
    	lcd_send_string("Green");

		lcd_goto_XY(1, 8);
		lcd_print_int(ns_time_left);
		lcd_goto_XY(2, 8);
		lcd_print_int(ew_time_left);

	        if (timer == 0) {
	            traffic_status = NS_RED_EW_YELLOW;
	            ew_time_left = yellow_duration;
	            timer = yellow_duration;
	        }
	        break;
	 case NS_RED_EW_YELLOW:
	        setLightV(red_light);
	        setLightH(yel_light);

	    	lcd_goto_XY(1, 0);
	    	lcd_send_string("Red");
	    	lcd_goto_XY(2, 0);
	    	lcd_send_string("Yellow");

			lcd_goto_XY(1, 8);
			lcd_print_int(ns_time_left);
			lcd_goto_XY(2, 8);
			lcd_print_int(ew_time_left);

	        if (timer == 0) {
	            traffic_status = NS_GREEN_EW_RED;
	            ns_time_left = green_duration;
	            ew_time_left = red_duration;
	            timer = green_duration;
	        }
	        break;
	}

	    ns_time_left--;
	    ew_time_left--;
	    timer--;
	    led1 = ns_time_left;
	    led2 = ew_time_left;



}





void fsm_automatic_run() {
    // Update timers
	switch (status){
	case INIT:
		if (isButtonPressed(0)){
			setLightH(red_light);
			setLightV(red_light);
	        status = MAN_RED;
	        timer4_flag = 1;
	        lcd_clear_display();
		}

		if (timer2_flag == 1){
			//update7SEG(led_index);

			setTimer_2(10);
		}

		if (timer1_flag == 1){
			auto_traffic();
			setTimer_1(1000);
		}

		break;
	case MAN_RED:
		if (isButtonPressed(0)){
			setLightH(yel_light);
			setLightV(yel_light);
	        status = MAN_YELLOW;
	        timer4_flag = 1;
	        lcd_clear_display();
		}

		lcd_goto_XY(1, 0);
		lcd_send_string("Mode");
		lcd_goto_XY(1, 8);
		lcd_print_int(1);
		lcd_goto_XY(2, 0);
		lcd_send_string("Count");
		lcd_goto_XY(2, 8);
		lcd_print_int(temp_red);

		if (isButtonPressed(1)){
			temp_red++;
			if (temp_red > 99) temp_red = 1;
		}

		if (isButtonPressed(2)){
			red_duration = temp_red;
			temp_red = 1;
		}

		if (timer2_flag == 1){
			led1 = 1;
			led2 = temp_red;
			//updateLED();
			//update7SEG(led_index);
	        lcd_clear_display();
			if (++led_index == 2) led_index = 0;
			setTimer_2(100);
		}

		if (timer3_flag == 1){
			if (red_flag == 1) {
				setLightH(0);
				setLightV(0); //turn off
			}
			else {
				setLightH(red_light);
				setLightV(red_light);
			}
			setTimer_3(250);
		}
		break;
	case MAN_YELLOW:
		if (isButtonPressed(0)){
	        setLightH(grn_light);
	        setLightV(grn_light);
	        status = MAN_GREEN;
	        timer4_flag = 1;
	        lcd_clear_display();
		}

		lcd_goto_XY(1, 0);
		lcd_send_string("Mode");
		lcd_goto_XY(1, 8);
		lcd_print_int(2);
		lcd_goto_XY(2, 0);
		lcd_send_string("Count");
		lcd_goto_XY(2, 8);
		lcd_print_int(temp_yellow);

		if (timer2_flag == 1){
			led1 = 2;
			led2 = temp_yellow;
			//updateLED();
			//update7SEG(led_index);
	        lcd_clear_display();
			if (++led_index == 2) led_index = 0;
			setTimer_2(100);
		}

		if (isButtonLongPressed(1)){
			if (timer4_flag == 1){
				temp_yellow++;
				if (temp_yellow > 99) temp_yellow = 1;
				setTimer_4(500);
			}
		}

		if (isButtonPressed(1)){
			temp_yellow++;
			if (temp_yellow > 99) temp_yellow = 1;
		}



		if (isButtonPressed(2)){
			yellow_duration = temp_yellow;
			temp_yellow = 1;
		}

		if (timer3_flag == 1){
			if (yel_flag == 1) {
				setLightH(0);
				setLightV(0); //turn off
			}
			else {
			setLightH(yel_light);
			setLightV(yel_light);
			}
			setTimer_3(250);
		}
		break;
	case MAN_GREEN:
		if (isButtonPressed(0)){
			//Swap yellow and green
			if (yellow_duration > green_duration) {
				green_duration = green_duration + yellow_duration;
			}
			if (red_duration < green_duration + yellow_duration){
				red_duration = green_duration + yellow_duration;
			}
			if (red_duration >= green_duration + yellow_duration){
				green_duration = red_duration - yellow_duration;
			}
			temp_red = 1;
			temp_yellow = 1;
			temp_green = 1;
			status = INIT;
			traffic_status = INIT;
	        timer4_flag = 1;
	        lcd_clear_display();
		}

		lcd_goto_XY(1, 0);
		lcd_send_string("Mode");
		lcd_goto_XY(1, 8);
		lcd_print_int(3);
		lcd_goto_XY(2, 0);
		lcd_send_string("Count");
		lcd_goto_XY(2, 8);
		lcd_print_int(temp_green);

		if (isButtonLongPressed(1)){
			if (timer4_flag == 1){
				temp_green++;
				if (temp_green > 99) temp_green = 1;
				setTimer_4(500);
			}
		}

		if (isButtonPressed(1)){
			temp_green++;
			if (temp_green > 99) temp_green = 1;
		}



		if (isButtonPressed(2)){
			green_duration = temp_green;
			temp_green = 1;
		}

		if (timer2_flag == 1){
			led1 = 3;
			led2 = temp_green;
			//updateLED();
			//update7SEG(led_index);
	        lcd_clear_display();
			if (++led_index == 2) led_index = 0;
			setTimer_2(100);
		}

		if (timer3_flag == 1){
			if (grn_flag == 1) {
				setLightH(0);
				setLightV(0); //turn off
			}
			else {
				setLightH(grn_light);
				setLightV(grn_light);
			}
			setTimer_3(250);
		}
		break;
	default:
		break;
	}


}
