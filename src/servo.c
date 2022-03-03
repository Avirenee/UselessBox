/*
 * servo.c
 *
 *  Created on: 20 janv. 2022
 *      Author: natha
 */
#include "stm32f1_timer.h"

#define PERIOD_TIMER 10

void SERVO_init(void)
{
TIMER_run_us(TIMER4_ID, PERIOD_TIMER*1000, FALSE); //10000us = 10ms
TIMER_run_us(TIMER4_ID, PERIOD_TIMER*1000, FALSE); //10000us = 10ms
TIMER_run_us(TIMER1_ID, PERIOD_TIMER*1000, FALSE); //10000us = 10ms

//activation du signal PWM sur le canal 1 du timer 1 (broche PA8)
TIMER_enable_PWM(TIMER4_ID, TIM_CHANNEL_1, 250, FALSE, FALSE);
TIMER_enable_PWM(TIMER4_ID, TIM_CHANNEL_2, 750, FALSE, FALSE);
TIMER_enable_PWM(TIMER1_ID, TIM_CHANNEL_3, 750, FALSE, FALSE);

//rapport cyclique reglé pour une position servo de 50%
SERVO1_set_position(0);
SERVO2_set_position(0);
}

void SERVO1_set_position(uint16_t position)
{
TIMER_set_duty(TIMER4_ID, TIM_CHANNEL_1, position+100);
}

void SERVO2_set_position(uint16_t position)
{
TIMER_set_duty(TIMER4_ID, TIM_CHANNEL_2, position+100);
}


