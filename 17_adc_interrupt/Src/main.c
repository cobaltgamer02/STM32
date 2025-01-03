#include<stdio.h>
#include<stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"

static void adc_callback(void);
uint32_t value;
int main() {

	uart2_rxtx_init();
	pa1_adc_interrupt_init();
	start_conversion();
	while (1) {

	}
}

static void adc_callback(){
	value = ADC1->DR;
	printf("Sensor value: %d\n\r", (int)value);
}
void ADC_IRQHandler(void){
	//Check for EOC in SR
			if((ADC1->SR & SR_EOC)!=0){
				//Clear EOC
				ADC1->SR &= ~SR_EOC;
				//do something
				adc_callback();
			}

}
