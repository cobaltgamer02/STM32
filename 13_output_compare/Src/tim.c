#include "stm32f4xx.h"

#define TIM2EN				(1U<<0)
#define CR1_EN			(1U<<0)
#define OC_TOGGLE	((1U<<4) | (1U<<5))
#define OC_ENABLE	(1U<<0)
#define GPIOAEN			(1U<<0)

void tim2_1hz_init(){
	//Enable clock access to Timer 2
	RCC->APB1ENR |= TIM2EN;
	//Set prescaler value
	TIM2->PSC = 1600-1; 		//	16 000 000/1600 = 10 000
	//Set auto reload value
	TIM2->ARR = 10000-1;		// 10 000/ 10 000 = 1
	//Clear counter
	TIM2->CNT = 0;
	//Enable timer
	TIM2->CR1 = CR1_EN;
}

void tim2_PA15_output_compare(){
	//Enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;
	//Set PA5 to alternate function
	GPIOA->MODER &=~(1U<<30);
	GPIOA->MODER |= (1U<<31);
	//Set PA15 alternate function type to TIM2_CH1 (AF1)
	GPIOA->AFR[1] |= (1U<<28);
	GPIOA->AFR[1] &= ~(1U<<29);
	GPIOA->AFR[1] &= ~(1U<<30);
	GPIOA->AFR[1] &= ~(1U<<31);
	//Enable clock access to Timer 2
	RCC->APB1ENR |= TIM2EN;
	//Set prescaler value
	TIM2->PSC = 1600-1; 		//	16 000 000/1600 = 10 000
	//Set auto reload value
	TIM2->ARR = 10000-1;		// 10 000/ 10 000 = 1
	//Set output compare toggle mode
	TIM2->CCMR1 = OC_TOGGLE;
	//Enable timer 2 ch 1 in compare mode
	TIM2->CCER = OC_ENABLE;
	//Clear counter
	TIM2->CNT = 0;
	//Enable timer
	TIM2->CR1 = CR1_EN;
}
