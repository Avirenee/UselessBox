/*
 * combinaisons.c
 *
 *  Created on: 12 janv. 2022
 *      Author: natha
 */
#include "macro_types.h"


int entree[] = {0,0,0,0,0};
int tabCombinaisons1[] = {1,1,1,1,1};
int tabCombinaisons2[] = {2,2,2,2,2};
int tabCombiRecu[5];
int valide=0;


void combinaison1()
{
	afficheMessage("DANSE DES ROBOTS", 30 ,100);

	for (int i=0; i<2; i++)
	{
	SERVO1_set_position(70);
	HAL_Delay(100);
	SERVO1_set_position(0);
	HAL_Delay(150);
	SERVO2_set_position(70);
	HAL_Delay(100);
	SERVO2_set_position(0);
	HAL_Delay(100);
	}
	HAL_Delay(150);
	SERVO1_set_position(70);
	SERVO2_set_position(70);
	HAL_Delay(200);
	SERVO1_set_position(0);
	SERVO2_set_position(0);
	HAL_Delay(75);
	SERVO1_set_position(70);
	SERVO2_set_position(70);
	HAL_Delay(200);
	SERVO1_set_position(0);
	SERVO2_set_position(0);

	effaceLigne(100);
}

void combinaison2()
{
	afficheMessage("J'hesite...",30,125);
	for (int pos=0; pos<=40; pos=pos+5)
	{
		SERVO1_set_position(pos);
		SERVO2_set_position(pos);
		HAL_Delay(200);
	}

	int pos=40;
	while (pos >5)
	{
		SERVO1_set_position(pos);
		SERVO2_set_position(pos);
		HAL_Delay(45);
		pos = pos-10;
	}
	HAL_Delay(200);
	for (int pos=0; pos<=70; pos=pos+5)
	{
		SERVO1_set_position(pos);
		SERVO2_set_position(pos);
		HAL_Delay(5);
	}
	effaceLigne(125);

}


void rechercheCombinaison(int *tabCombinaisons1 , int *tabCombinaisons2 , int *combinaisonEnCours)
{
	uint8_t valide_1 = 0;
	uint8_t valide_2 = 0;

	for (int i=0; i<5; i++)
		{
			if (combinaisonEnCours[i] == tabCombinaisons1[i])		//si elle est reconnue
				{
					valide_1++;
				}
			if (combinaisonEnCours[i] == tabCombinaisons2[i])		//si elle est reconnue
				{
					valide_2++;
				}
		}
	if(valide_1 > 4) //si combinaison 1
		{
			combinaison1();
		}
				else if(valide_2 > 4)
					{
						combinaison2();
					}
				else
					effaceLigne(60);

}
