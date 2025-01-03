#include<stdio.h>
#include<stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"
//PA6 AF2
#define GPIODEN										(1U<<3)
#define PIN12											   (1U<<12)
#define LED_PIN										PIN12

static void exti_callback(void);

int main() {
	//1. Give clock access to GPIOD
	RCC->AHB1ENR |= GPIODEN;
	// 2. Set PD12 as output pin
	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &= ~(1U<<25);

	pa3_exti_init();
	uart2_tx_init();

	while (1) {

	}
}

static void exti_callback(void){
	printf("BTN pressed...\n\r");
	GPIOD->ODR ^= LED_PIN;
}

void EXTI0_IRQHandler(void){
	if((EXTI->PR & (1U<<0)) != 0){
		//Clear The PR flag
		EXTI-> PR |= (1U<<0);
		//Do something
		exti_callback();
	}
}
