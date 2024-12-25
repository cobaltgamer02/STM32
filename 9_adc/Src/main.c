//Where is the green led connected?
//Port: D
//Pin: 12

// Push Button PA0
#include "stm32f4xx.h"
#define GPIOAEN										(1U<<0)
#define GPIODEN										(1U<<3)

#define PIN0												(1U<<0)
#define PIN12											   (1U<<12)

#define BTN_PIN										PIN0
#define LED_PIN										PIN12

int main() {
	// 1. Enable clock access to GPIOD
	RCC->AHB1ENR |= GPIOAEN;
	RCC->AHB1ENR |= GPIODEN;
	// 2. Set PD12 as output pin
	GPIOD->MODER |= (1U << 24);
	GPIOD->MODER &= ~(1U << 25);
	//3. Set PA0 as input pin
	GPIOA->MODER &= ~(1U << 0);
	GPIOA->MODER &= ~(1U << 1);
	while (1) {
		/*Check if btn is pressed*/
		if (GPIOA->IDR & BTN_PIN) {
			//Turn On
			GPIOD->BSRR = (LED_PIN);
		} else {
			//Turn Off
			GPIOD->BSRR = (1U << 28);
		}
	}
}
