//Where is the green led connected?
//Port: D, Pin: 12

// Push Button PA0
#include "exti.h"

#define GPIOAEN 				(1U<<0)
#define SYSCFGEN			(1U<<14)

void pa3_exti_init(){
	//Disable global interrupts (optional but good practice)
	__disable_irq();
	//Enable clock access for GPIOA
	RCC->AHB1ENR |= GPIOAEN;
	//Set PA0 as input
	GPIOA->MODER &= ~(1U<<0);
	GPIOA->MODER &= ~(1U<<1);
	//Enable clock access to SYSCFG
	RCC->APB2ENR |= SYSCFGEN;
	//Select Port A for EXTI0
	SYSCFG->EXTICR[0]	&= ~(1U<<0);
	SYSCFG->EXTICR[0]	&= ~(1U<<1);
	SYSCFG->EXTICR[0]	&= ~(1U<<2);
	SYSCFG->EXTICR[0]	&= ~(1U<<3);
	//Unmask EXTI0
	EXTI->IMR |= (1U<<0);
	//Select falling edge trigger
	EXTI->FTSR |= (1U<<0);
	//Enable EXTI0 line in NVIC
	NVIC_EnableIRQ(EXTI0_IRQn);
	//Enable global interrupts
	__enable_irq();
}