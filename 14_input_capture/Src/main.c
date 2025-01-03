#include<stdio.h>
#include<stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"
#include "tim.h"
//PA6 AF2

int timestamp = 0;
//set up: connect a jumper wire from pa15 to pa6
int main() {

	tim2_PA15_output_compare();
	tim3_PA6_input_compare();

	while (1) {
		//Wait until edge is captured
		while(!(TIM2->SR  & SR_CC1IF)){}
		//Read value
		timestamp = TIM3->CCR1;
	}
}
