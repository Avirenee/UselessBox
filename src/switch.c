/*
 * switch.c
 *
 *  Created on: 28 janv. 2022
 *      Author: natha
 */

#define SWITCH1_GPIOPORT GPIOB
#define SWITCH1_Pin 	GPIO_PIN_13
#define SWITCH2_GPIOPORT GPIOB
#define SWITCH2_Pin 	GPIO_PIN_12

bool_e readSwitch1(void)
{
	return !HAL_GPIO_ReadPin(SWITCH1_GPIOPORT, SWITCH1_Pin);
}

bool_e readSwitch2(void)
{
	return !HAL_GPIO_ReadPin(SWITCH2_GPIOPORT, SWITCH2_Pin);
}
