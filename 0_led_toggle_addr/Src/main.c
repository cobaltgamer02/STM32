//Where is the green led connected?
//Port: D
//Pin: 12

#define PERIPH_BASE							(0x40000000UL)
#define AHB1PERIPH_OFFSET			(0x00020000UL)

#define AHB1PERIPH_BASE				(PERIPH_BASE + AHB1PERIPH_OFFSET)

#define GPIOD_OFFSET						(0x0C00UL)
#define GPIOD_BASE							(AHB1PERIPH_BASE + GPIOD_OFFSET)

#define RCC_OFFSET 							(0x3800UL)
#define RCC_BASE								(AHB1PERIPH_BASE + RCC_OFFSET)

#define AHB1ENR_OFFSET				(0x30UL)
#define RCC_AHB1ENR						(*(volatile unsigned int *)(RCC_BASE + AHB1ENR_OFFSET))

#define MODER_OFFSET					(0x00UL)
#define GPIOD_MODER						(*(volatile unsigned int *)(GPIOD_BASE + MODER_OFFSET))

#define ODR_OFFSET							(0x14UL)
#define GPIOD_ODR							(*(volatile unsigned int *)(GPIOD_BASE + ODR_OFFSET))

#define GPIODEN										(1U<<3)
#define PIN12											(1U<<12)
#define LED_PIN										PIN12




int main()
{
	// 1. Enable clock access to GPIOD
	RCC_AHB1ENR |= GPIODEN;

	// 2. Set PD12 as output pin
	GPIOD_MODER |= (1U<<24);
	GPIOD_MODER &= ~(1U<<25);

	while(1){
		//3.  Set 	PD12 high
		//GPIOD_ODR |= LED_PIN;
		//4. Toggle PD12
		GPIOD_ODR ^= LED_PIN;
		for(int i=0; i<100000; i++){}
	}
}



