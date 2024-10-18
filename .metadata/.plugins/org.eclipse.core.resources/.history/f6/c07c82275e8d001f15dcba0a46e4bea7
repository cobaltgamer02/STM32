//Where is the green led connected?
//Port: D
//Pin: 12
#include "stm32f4xx.h"

#define GPIODEN										(1U<<3)
#define PIN12											   (1U<<12)
#define LED_PIN										PIN12

int main()
{
	// 1. Enable clock access to GPIOD
	RCC->AHB1ENR |= GPIODEN;
	// 2. Set PD12 as output pin
	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &= ~(1U<<25);
	while(1){
		//3.  Set 	PD12 high
		GPIOD->BSRR = (LED_PIN);
		for(int i=0; i<100000; i++){}

		GPIOD->BSRR = (1U<<28);
		for(int i=0; i<100000; i++){}
	}
}
