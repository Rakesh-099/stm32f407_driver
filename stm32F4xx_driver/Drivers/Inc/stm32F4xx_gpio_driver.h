/*
 * stm32F4xx_gpio_driver.h
 *
 *  Created on: Mar 18, 2024
 *      Author: Rakesh
 */

#ifndef INC_STM32F4XX_GPIO_DRIVER_H_
#define INC_STM32F4XX_GPIO_DRIVER_H_

#include "stm32F4xx.h"


typedef struct{
	uint8_t GPIO_PinNumber;							/*Possible values are @@GPIO_PIN_NUMBERS */
	uint8_t GPIO_PinMode;							/*Possible values are @GPIO_PIN_MODES */
	uint8_t GPIO_PinSpeed;							/*Possible values are @@GPIO_PIN_SPEED */
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;

/*
 * This is a Handle structure for a GPIO pin
 */


typedef struct{
	GPIO_RegDef_t *pGPIOx;                              /*This holds the base address of GPIO port*/
	GPIO_PinConfig_t GPIO_PinConfig;					/*This holds the GPIO configuration settings*/
}GPIO_Handle_t;

/*
 * @GPIO_PIN_NUMBERS
 * GPIO PIN NUMBERS
 */
#define GPIO_PIN_NUM_0				0
#define GPIO_PIN_NUM_1				1
#define GPIO_PIN_NUM_2				2
#define GPIO_PIN_NUM_3				3
#define GPIO_PIN_NUM_4				4
#define GPIO_PIN_NUM_5				5
#define GPIO_PIN_NUM_6				6
#define GPIO_PIN_NUM_7				7
#define GPIO_PIN_NUM_8				8
#define GPIO_PIN_NUM_9				9
#define GPIO_PIN_NUM_10				10
#define GPIO_PIN_NUM_11				11
#define GPIO_PIN_NUM_12				12
#define GPIO_PIN_NUM_13				13
#define GPIO_PIN_NUM_14				14
#define GPIO_PIN_NUM_15				15
/*
 * @GPIO_PIN_MODES
 * GPIO Pin Possible Mode
 */

#define GPIO_MODE_IN		0
#define GPIO_MODE_OUT		1
#define	GPIO_MODE_ALTFN		2
#define GPIO_MODE_ANALOG	3
#define	GPIO_MODE_IT_FT		4
#define GPIO_MODE_IT_RT		5
#define GPIO_MODE_IT_RFT 	6

/*
 * GPIO pin Possible output types
 */

#define GPIO_OP_TYPE_PP		0
#define GPIO_OP_TYPE_OD		1

/*
 * @GPIO_PIN_SPEED
 * GPIO Pin Possible output speed
 */
#define GPIO_SPEED_LOW		0
#define GPIO_SPEED_MEDIUM	1
#define	GPIO_SPEED_FAST		2
#define GPIO_SPEED_HIGH		3


/*
 * GPIO Pin Pull up pull down Configuration macros
 */
#define GPIO_NO_PUPD		0
#define GPIO_PIN_PU			1
#define GPIO_PIN_PD			2

/*                APIs support this driver                             */

/*
 * Peripheral Clock Setup
  */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx,uint8_t EnorDi);
/*
 * Init and DeInit
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);
/*
 * Data read and write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber,uint8_t value);
void GPIO_writeToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t value);
void GPIO_ToggleOutPutPin(GPIO_RegDef_t *pGPIOx,uint8_t PinNumber);
/*
 * IRQ Configuration and ISR Handling
 */
void GPIO_IRQConfig(uint8_t IRQNumber,uint8_t IRQPriority,uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);














#endif /* INC_STM32F4XX_GPIO_DRIVER_H_ */
