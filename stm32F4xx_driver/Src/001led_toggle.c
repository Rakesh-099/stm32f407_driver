/*
 * 001led_toggle.c
 *
 *  Created on: Mar 20, 2024
 *      Author: Rakesh
 */


#include "stm32F4xx.h"
#include "stm32F4xx_gpio_driver.h"


void delay()
{
	for(uint32_t i=0; i < 500000;i++);
}
int main(void)
{
	GPIO_Handle_t GPIOLed;
	GPIOLed.pGPIOx = GPIOD;
	GPIOLed.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NUM_12;
	GPIOLed.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIOLed.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOLed.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIOLed.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_PeriClockControl(GPIOD, ENABLE);

	GPIO_Init(&GPIOLed);
	while(1)
	{
		GPIO_ToggleOutPutPin(GPIOD, GPIO_PIN_NUM_12);
		delay();
	}
	return 0;
}
