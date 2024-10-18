//Where is the green led connected?
//Port: D
//Pin: 12
#include<stdint.h>

#define PERIPH_BASE							(0x40000000UL)
#define AHB1PERIPH_OFFSET			(0x00020000UL)

#define AHB1PERIPH_BASE				(PERIPH_BASE + AHB1PERIPH_OFFSET)

#define GPIOD_OFFSET						(0x0C00UL)
#define GPIOD_BASE							(AHB1PERIPH_BASE + GPIOD_OFFSET)

#define RCC_OFFSET 						(0x3800UL)
#define RCC_BASE								(AHB1PERIPH_BASE + RCC_OFFSET)

#define GPIODEN										(1U<<3)
#define PIN12											(1U<<12)
#define LED_PIN										PIN12

#define __IO volatile

typedef struct
{
	volatile uint32_t MODER;
	volatile uint32_t DUMMY[4];
	volatile uint32_t ODR;
}GPIO_TypeDef;

typedef struct
{
	volatile uint32_t DUMMY[12];
	volatile uint32_t AHB1ENR;
}RCC_TypeDef;

#define RCC											((RCC_TypeDef*) RCC_BASE)
#define GPIOD										((GPIO_TypeDef*) GPIOD_BASE)


int main()
{
	// 1. Enable clock access to GPIOD
	RCC->AHB1ENR |= GPIODEN;
	// 2. Set PD12 as output pin
	GPIOD->MODER |= (1U<<24);
	GPIOD->MODER &= ~(1U<<25);
	while(1){
		//3.  Set 	PD12 high
		//GPIOD->ODR |= LED_PIN;
		//4. Toggle PD12
		//GPIOD->ODR ^= LED_PIN;
		GPIOD->ODR &= ~(LED_PIN);
		for(int i=0; i<100000; i++){}
	}
}



