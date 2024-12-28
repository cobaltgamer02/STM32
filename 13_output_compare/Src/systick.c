#include "stm32f4xx.h"

#define SYSTIC_LOAD_VAL				16000
#define CTRL_ENABLE						(1U<<0)
#define CTRL_CLCKSRC					(1U<<2)
#define CTRL_COUNTFLAG				(1U<<16)

void systickDelayMs(int delay){
	//Reload with number of clocks per ms
	SysTick->LOAD = SYSTIC_LOAD_VAL;
	//Clear systick current value register
	SysTick->VAL = 0;
	//Enable systick and select internal clk src
	SysTick->CTRL = CTRL_ENABLE | CTRL_CLCKSRC;

	for(int i=0; i<delay; i++){
		//Wait until count flag is set
		while((SysTick->CTRL & CTRL_COUNTFLAG)==0){}
	}
	SysTick->CTRL =0;

}
