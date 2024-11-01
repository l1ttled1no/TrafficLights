/*
 * global.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */
#include "global.h"

//void display7SEG(int num){
//
//	//Set to initial state
//		/*HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, SET);
//	    HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, SET);
//	    HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, SET);
//	    HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
//	    HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
//	    HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
//	    HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);*/
//
//
//		switch (num){
//		case 0:
//		    HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);
//		    break;
//		case 1:
//		    HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);
//		    break;
//		case 2:
//		    HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
//		    break;
//		case 3:
//		    HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
//		    break;
//		case 4:
//		    HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
//		    break;
//		case 5:
//		    HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
//		    break;
//		case 6:
//		    HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
//		    break;
//		case 7:
//		    HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, SET);
//		    break;
//		case 8:
//		    HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
//		    break;
//		case 9:
//		    HAL_GPIO_WritePin(SEG_A_GPIO_Port, SEG_A_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_B_GPIO_Port, SEG_B_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_C_GPIO_Port, SEG_C_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_D_GPIO_Port, SEG_D_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_E_GPIO_Port, SEG_E_Pin, SET);
//		    HAL_GPIO_WritePin(SEG_F_GPIO_Port, SEG_F_Pin, RESET);
//		    HAL_GPIO_WritePin(SEG_G_GPIO_Port, SEG_G_Pin, RESET);
//		    break;
//		default:
//			break;
//		}
//
//}
//
//void display7SEG2(int num){
//    switch (num){
//    case 0:
//        HAL_GPIO_WritePin(SEG_A2_GPIO_Port, SEG_A2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_B2_GPIO_Port, SEG_B2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_C2_GPIO_Port, SEG_C2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_D2_GPIO_Port, SEG_D2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_E2_GPIO_Port, SEG_E2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_F2_GPIO_Port, SEG_F2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_G2_GPIO_Port, SEG_G2_Pin, SET);
//        break;
//    case 1:
//        HAL_GPIO_WritePin(SEG_A2_GPIO_Port, SEG_A2_Pin, SET);
//        HAL_GPIO_WritePin(SEG_B2_GPIO_Port, SEG_B2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_C2_GPIO_Port, SEG_C2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_D2_GPIO_Port, SEG_D2_Pin, SET);
//        HAL_GPIO_WritePin(SEG_E2_GPIO_Port, SEG_E2_Pin, SET);
//        HAL_GPIO_WritePin(SEG_F2_GPIO_Port, SEG_F2_Pin, SET);
//        HAL_GPIO_WritePin(SEG_G2_GPIO_Port, SEG_G2_Pin, SET);
//        break;
//    case 2:
//        HAL_GPIO_WritePin(SEG_A2_GPIO_Port, SEG_A2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_B2_GPIO_Port, SEG_B2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_C2_GPIO_Port, SEG_C2_Pin, SET);
//        HAL_GPIO_WritePin(SEG_D2_GPIO_Port, SEG_D2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_E2_GPIO_Port, SEG_E2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_F2_GPIO_Port, SEG_F2_Pin, SET);
//        HAL_GPIO_WritePin(SEG_G2_GPIO_Port, SEG_G2_Pin, RESET);
//        break;
//    case 3:
//        HAL_GPIO_WritePin(SEG_A2_GPIO_Port, SEG_A2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_B2_GPIO_Port, SEG_B2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_C2_GPIO_Port, SEG_C2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_D2_GPIO_Port, SEG_D2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_E2_GPIO_Port, SEG_E2_Pin, SET);
//        HAL_GPIO_WritePin(SEG_F2_GPIO_Port, SEG_F2_Pin, SET);
//        HAL_GPIO_WritePin(SEG_G2_GPIO_Port, SEG_G2_Pin, RESET);
//        break;
//    case 4:
//        HAL_GPIO_WritePin(SEG_A2_GPIO_Port, SEG_A2_Pin, SET);
//        HAL_GPIO_WritePin(SEG_B2_GPIO_Port, SEG_B2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_C2_GPIO_Port, SEG_C2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_D2_GPIO_Port, SEG_D2_Pin, SET);
//        HAL_GPIO_WritePin(SEG_E2_GPIO_Port, SEG_E2_Pin, SET);
//        HAL_GPIO_WritePin(SEG_F2_GPIO_Port, SEG_F2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_G2_GPIO_Port, SEG_G2_Pin, RESET);
//        break;
//    case 5:
//        HAL_GPIO_WritePin(SEG_A2_GPIO_Port, SEG_A2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_B2_GPIO_Port, SEG_B2_Pin, SET);
//        HAL_GPIO_WritePin(SEG_C2_GPIO_Port, SEG_C2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_D2_GPIO_Port, SEG_D2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_E2_GPIO_Port, SEG_E2_Pin, SET);
//        HAL_GPIO_WritePin(SEG_F2_GPIO_Port, SEG_F2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_G2_GPIO_Port, SEG_G2_Pin, RESET);
//        break;
//    case 6:
//        HAL_GPIO_WritePin(SEG_A2_GPIO_Port, SEG_A2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_B2_GPIO_Port, SEG_B2_Pin, SET);
//        HAL_GPIO_WritePin(SEG_C2_GPIO_Port, SEG_C2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_D2_GPIO_Port, SEG_D2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_E2_GPIO_Port, SEG_E2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_F2_GPIO_Port, SEG_F2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_G2_GPIO_Port, SEG_G2_Pin, RESET);
//        break;
//    case 7:
//        HAL_GPIO_WritePin(SEG_A2_GPIO_Port, SEG_A2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_B2_GPIO_Port, SEG_B2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_C2_GPIO_Port, SEG_C2_Pin, RESET);
//        HAL_GPIO_WritePin(SEG_D2_GPIO_Port, SEG_D2_Pin, SET);
//        HAL_GPIO_WritePin(SEG_E2_GPIO_Port, SEG_E2_Pin, SET);
//        HAL_GPIO_WritePin(SEG_F2_GPIO_Port, SEG_F2_Pin, SET);
//        HAL_GPIO_WritePin(SEG_G2_GPIO_Port, SEG_G2_Pin, SET);
//        break;
//    case 8:
//         HAL_GPIO_WritePin(SEG_A2_GPIO_Port, SEG_A2_Pin, RESET);
//         HAL_GPIO_WritePin(SEG_B2_GPIO_Port, SEG_B2_Pin, RESET);
//         HAL_GPIO_WritePin(SEG_C2_GPIO_Port, SEG_C2_Pin, RESET);
//         HAL_GPIO_WritePin(SEG_D2_GPIO_Port, SEG_D2_Pin, RESET);
//         HAL_GPIO_WritePin(SEG_E2_GPIO_Port, SEG_E2_Pin, RESET);
//         HAL_GPIO_WritePin(SEG_F2_GPIO_Port, SEG_F2_Pin, RESET);
//         HAL_GPIO_WritePin(SEG_G2_GPIO_Port, SEG_G2_Pin, RESET);
//         break;
//    case 9:
//         HAL_GPIO_WritePin(SEG_A2_GPIO_Port, SEG_A2_Pin, RESET);
//         HAL_GPIO_WritePin(SEG_B2_GPIO_Port, SEG_B2_Pin, RESET);
//         HAL_GPIO_WritePin(SEG_C2_GPIO_Port, SEG_C2_Pin, RESET);
//         HAL_GPIO_WritePin(SEG_D2_GPIO_Port, SEG_D2_Pin, RESET);
//         HAL_GPIO_WritePin(SEG_E2_GPIO_Port, SEG_E2_Pin, SET);
//         HAL_GPIO_WritePin(SEG_F2_GPIO_Port, SEG_F2_Pin, RESET);
//         HAL_GPIO_WritePin(SEG_G2_GPIO_Port, SEG_G2_Pin, RESET);
//         break;
//     default:
//         break;
//        }
//    }
//
//
//void update7SEG(int index){
//    // Turn off all displays first
//    HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, SET);
//    HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, SET);
//    HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_0_Pin, SET);
//    HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_1_Pin, SET);
//    // Select the appropriate display and show the digit
//    switch (index){
//    case 0:
//        HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, RESET);
//        HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, RESET);
//        HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, SET);
//        HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, SET);
//        display7SEG(segment_buffer[0]);
//        display7SEG2(segment_buffer[1]);
//        break;
//    case 1:
//        HAL_GPIO_WritePin(EN_0_GPIO_Port, EN_0_Pin, SET);
//        HAL_GPIO_WritePin(EN_1_GPIO_Port, EN_1_Pin, SET);
//        HAL_GPIO_WritePin(EN_2_GPIO_Port, EN_2_Pin, RESET);
//        HAL_GPIO_WritePin(EN_3_GPIO_Port, EN_3_Pin, RESET);
//        display7SEG(segment_buffer[2]);
//        display7SEG2(segment_buffer[3]);
//        break;
//    default:
//        break;
//    }
//}
