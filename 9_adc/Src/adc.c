#include "stm32f4xx.h"
#include "adc.h"

#define GPIOAEN					(1U<<0)
#define ADC1EN						(1U<<8)
#define ADC_CH1					(1U<<0)
#define ADC_SEQ_LEN1	0x00
#define CR2_AD0N				(1U<<0)
#define CR2_SWSTART		(1U<<30)
#define SR_EOC					(1U<<1)


void pa1_adc_init(void){
	//1. Configure the ADC GPIO Pin
	//Enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;
	//Set the mode of PA1 to analog
	GPIOA->MODER |=(1U<<2);
	GPIOA->MODER |=(1U<<3);

	//2. Configure the ADC Module
	//Enable clock access to ADC
	RCC->APB2ENR |= ADC1EN;
	//Configure the ADC parameters

	//Conversion sequence start
	ADC1->SQR3 = ADC_CH1;
	//Conversion sequence length
	ADC1->SQR1 = ADC_SEQ_LEN1;
	//Enable ADC module
	ADC1->CR2 |= CR2_AD0N;

}

void start_conversion(void){
	//Start ADC Conversion
	ADC1->CR2 |= CR2_SWSTART;
}

uint32_t adc_read(){
	//Wait for conversion to be completed
	while(!(ADC1->SR & SR_EOC)){}
	//Read converted result
	return (ADC1->DR);
}


