/*
 * File name            : main.c
 * Compiler             : MDK-Lite
 * IDE                  : Keil uVision V5
 * Author               : Etiq Technologies
 * Processor            : LPC1768
 * Created on           : June 09, 2017, 9:44 AM
 * Description          : Switch Program
 */

#include <lpc17xx.h>

#define DATA_DIR	   LPC_GPIO1->FIODIR
#define DATA_SET	   LPC_GPIO1->FIOSET
#define DATA_CLR	   LPC_GPIO1->FIOCLR
#define DATA_PIN		 LPC_GPIO1->FIOPIN

#define PIN_D0 24
#define PIN_D1 25
#define PIN_D2 26
#define PIN_D3 27
#define PIN_D4 28
#define PIN_D5 29
#define PIN_D6 30
#define PIN_D7 31

int main()
{
	int i = PIN_D1;
	SystemInit();
	DATA_DIR = (0xFE << PIN_D0);
	while(1)
	{
		if(!((DATA_PIN >> PIN_D0)&0x01))
		{
			while(!((DATA_PIN >> PIN_D0)&0x01));				// Prevent Debouncing
			DATA_CLR = (0xFE << PIN_D0);
			DATA_SET = (1 << i);
			i++;
		}
	if(i > PIN_D7)
		i = PIN_D1;
	}
}