#include<stdio.h>
#include<stdint.h>
#include "stm32f4xx.h"
#include "uart.h"
#include "adc.h"

uint32_t value;
int main() {

	uart2_rxtx_init();
	pa1_adc_init();
	start_conversion();
	while (1) {
		value = adc_read();
		printf("Sensor value: %d\n\r", (int)value);
	}
}
