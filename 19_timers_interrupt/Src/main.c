#include<stdio.h>
#include<stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"


#define GPIODEN										(1U<<3)
#define PIN12											   (1U<<12)
#define LED_PIN										PIN12
static void tim2_callback();

int main() {
	RCC->AHB1ENR |= GPIODEN;
	// 2. Set PD12 as output pin
	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &= ~(1U<<25);


	uart2_tx_init();
	tim2_1hz_interrupt_init();
	while (1) {

	}
}

static void tim2_callback(){
	printf("A second is passed Timer....\n\r");
	GPIOD->ODR ^= LED_PIN;
}

void TIM2_IRQHandler(){
	//Clear update interrupt flag
	TIM2->SR &=~ SR_UIF;
	//Do something
	tim2_callback();
}
