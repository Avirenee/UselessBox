/**
  ******************************************************************************
  * @file    main.c
  * @author  Nirgal
  * @date    03-July-2019
  * @brief   Default main function.
  ******************************************************************************
*/
#include "stm32f1xx_hal.h"
#include "stm32f1_uart.h"
#include "stm32f1_sys.h"
#include "stm32f1_gpio.h"
#include "stm32f1_timer.h"
#include "macro_types.h"
#include "systick.h"
#include "stm32f1_ili9341.h"

#include "switch.h"
#include "combinaisons.h"
#include "servo.h"
#include "ecran.h"

#define LED_GREEN2_GPIO GPIOA
#define LED_GREEN2_PIN GPIO_PIN_15
#define SERVO2_PORT GPIOB
#define SERVO2_Pin GPIO_PIN_7
#define SERVO1_PORT GPIOB
#define SERVO1_Pin GPIO_PIN_6


int main(void)
{

// Initialisation des Periphériques

	HAL_Init();
	BSP_GPIO_Enable();




// Configuration des ports

	BSP_GPIO_PinCfg(LED_BLUE_GPIO, LED_BLUE_PIN, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(LED_GREEN2_GPIO, LED_GREEN2_PIN, GPIO_MODE_OUTPUT_PP,GPIO_NOPULL,GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(SERVO1_PORT, SERVO1_Pin, GPIO_MODE_OUTPUT_PP , GPIO_NOPULL , GPIO_SPEED_FREQ_HIGH);
	BSP_GPIO_PinCfg(SERVO2_PORT, SERVO2_Pin, GPIO_MODE_OUTPUT_PP , GPIO_NOPULL , GPIO_SPEED_FREQ_HIGH);
	ILI9341_Init();
	SERVO_init();




// Initialisation des combinaisons

	static int tabCombinaisons1[] = {1,1,1,1,1};
	static int tabCombinaisons2[] = {2,2,2,2,2};




// Initialisation des variables

	uint8_t indexCombi=0;
	int combinaisonEnCours[5];
	bool_e entrant = TRUE;




// Affichage page d'acceuil

	afficheEcranInit();




// Tâche de fond

	while(1)
	{
		while(readSwitch1())
		{
			HAL_GPIO_WritePin(LED_BLUE_GPIO, LED_BLUE_PIN, 0);
			SERVO1_set_position(70);
			if (entrant)	// Si on n'a pas déjà compté l'appui
			{
			combinaisonEnCours[indexCombi]= 1;
			indexCombi++;
			entrant = FALSE;

			}
		}
		HAL_GPIO_WritePin(LED_BLUE_GPIO, LED_BLUE_PIN, 1);
		SERVO1_set_position(0);
		entrant = TRUE;


		while(readSwitch2())
		{
			HAL_GPIO_WritePin(LED_BLUE_GPIO, LED_BLUE_PIN, 0);
			SERVO2_set_position(70);
			if (entrant)	// si on n'a pas déjà compté l'appui
			{
				combinaisonEnCours[indexCombi]= 2;
				indexCombi++;
				entrant = FALSE;
			}
		}
		HAL_GPIO_WritePin(LED_BLUE_GPIO, LED_BLUE_PIN, 1);
		SERVO2_set_position(0);
		entrant = TRUE;


		if (indexCombi == 5)
		{
			rechercheCombinaison(tabCombinaisons1 , tabCombinaisons2 , combinaisonEnCours);
			for (int i =0; i <5; i++)
			{
				combinaisonEnCours[i] = 0;
			}
			indexCombi=0;
		}
	}
}
