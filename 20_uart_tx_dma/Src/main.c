#include<stdio.h>
#include<stdint.h>
#include "stm32f4xx.h"
#include "uart.h"

#define GPIODEN										(1U<<3)
#define PIN12											   (1U<<12)
#define LED_PIN										PIN12


static void dma_callback(void);

int main() {
	char message[31] = "Hello from STM32 DMA transfer\n\r";
	// 1. Enable clock access to GPIOD
	RCC->AHB1ENR |= GPIODEN;
	// 2. Set PD12 as output pin
	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &= ~(1U<<25);

	uart2_tx_init();
	dma1_stream6_init((uint32_t)message, (uint32_t) &USART2->DR, 31);
	while (1) {

	}
}

static void dma_callback(void){
	GPIOD->ODR ^= LED_PIN;
}

void DMA1_Stream6_IRQHandler(void){
	//Check for transfer complete interrupt
	if(DMA1->HISR & HISR_TC1F6){
		//Clear flag
		DMA1->HIFCR |= HIFCR_CTCIF6;
		//Do something
		dma_callback();
	}
}
