/*
 * ecran.c
 *
 *  Created on: 5 janv. 2022
 *      Author: natha
 */

#include "macro_types.h"
#include "stm32f1_ili9341.h"

void afficheEcranInit(void)
{
	afficheMessage("Bienvenue sur la" , 30 , 0);
	afficheMessage("Useless Box" , 60 , 30);
}

void afficheMessage(char* chaine , uint16_t x , uint16_t y)
{
	ILI9341_Puts( x , y , chaine , &Font_11x18, ILI9341_COLOR_BROWN,ILI9341_COLOR_WHITE);
	HAL_Delay(15);
}

void effaceLigne( uint16_t y )
{
	uint16_t k = 0;
	while(k < 230)
	{
		ILI9341_Puts( k , y , " " , &Font_11x18, ILI9341_COLOR_BROWN,ILI9341_COLOR_WHITE);
		k = (uint16_t)(k + 10);
	}
}

void afficheTableau(int tab[] , uint16_t x , uint16_t y)
{
	for (int k = 0 ; k < 5 ; k++)
	{
		afficheMessage(itoa(tab[k]), k*x , y);
	}
}
