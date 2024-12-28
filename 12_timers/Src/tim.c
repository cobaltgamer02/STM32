#include "stm32f4xx.h"

#define TIM2EN				(1U<<0)
#define CR1_EN			(1U<<0)

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

