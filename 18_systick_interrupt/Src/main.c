#include<stdio.h>
#include<stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"

#define GPIODEN										(1U<<3)
#define PIN12											   (1U<<12)
#define LED_PIN										PIN12

static void systick_callback();

int main() {
	RCC->AHB1ENR |= GPIODEN;
	// 2. Set PD12 as output pin
	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &= ~(1U<<25);


	uart2_tx_init();
	void systick_1hz_interrupt(void);
	while (1) {

	}
}

static void systick_callback(){
	//3.  toggle led and print
	printf("A second is passed....\n\r");
	GPIOD->ODR ^= LED_PIN;
}

void SysTick_Handler(void){
	//Do Something
	systick_callback();
}
