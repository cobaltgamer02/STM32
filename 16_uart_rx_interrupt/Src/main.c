#include<stdio.h>
#include<stdint.h>
#include "stm32f4xx.h"
#include "uart.h"

#define GPIODEN										(1U<<3)
#define PIN12											   (1U<<12)
#define LED_PIN										PIN12


static void uart_callback(void);

char key;
int main() {
	// 1. Enable clock access to GPIOD
	RCC->AHB1ENR |= GPIODEN;
	// 2. Set PD12 as output pin
	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &= ~(1U<<25);

	uart2_rx_interrupt_init();

	while (1) {

	}
}

static void uart_callback(){
	key = USART2->DR;
			if(key == '1'){
						GPIOD->ODR |=  LED_PIN;

					}
					else{
						GPIOD->ODR &= ~(LED_PIN);
					}
}

void USART2_IRQHandler(void){
	//Check is RXNE is set
	if(USART2->SR  & SR_RXNE){
		//Do something
		uart_callback();
	}
}
