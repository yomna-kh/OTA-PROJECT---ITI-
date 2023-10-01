#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "MCAL/RCC/RCC_int.h"
#include "MCAL/UART/UART_int.h"
#include "MCAL/NVIC/NVIC_int.h"
#include "MCAL/SYSTICK/STK_int.h"
#include "HEX_FILE.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/EXTI/EXTI_int.h"
u8 flag = 0;


USART_InitType x = {
		9600,
		USART_MODE_8BIT,
		USART_STOP_BIT_1,
		DISABLE,
		USART_EVEN_PARITY,
		USART_TX_RX	,
		USART_OVER_SAMPLING_16};



void  main(void)
{
	MRCC_vInit();
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOA);
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOB);

	MRCC_vEnableClock(RCC_APB1,RCC_EN_UART2);
	//	A2,A3
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_MODE_ALTFUN);
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_MODE_ALTFUN);
	MGPIO_vSetPinOutputType(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUTTYPE_PUSHPULL);
	MGPIO_vSetPinOutputType(GPIO_PORTA,GPIO_PIN3,GPIO_OUTPUTTYPE_PUSHPULL);
	MGPIO_vSetPinOutputSpeed(GPIO_PORTA,GPIO_PIN2,GPIO_OUTSPEED_LOW);
	MGPIO_vSetPinOutputSpeed(GPIO_PORTA,GPIO_PIN3,GPIO_OUTSPEED_LOW);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN2,7);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN3,7);


	MUSART_vInit(&x, USART2);
	MUSART_vEnable(USART2);


	u8 Flag =1 ;
	//u8 message0[2] = "hi";
	while (Flag==1)
	{
		for (u8 i = 0; i < sizeof(array) / sizeof(array[0]); i++)
		{
			u8 j = 0;
			while (array[i][j] != '\0')
			{
				MUSART_vTransmitByteSynch(USART2, array[i][j]);
				j++;
			}

			MUSART_vTransmitByteSynch(USART2, '\0');

		}
		u8 status = MUSART_u8ReceiveByteSynchBlocking(USART2);
		while ( status != 'K')
		{
			 status = MUSART_u8ReceiveByteSynchBlocking(USART2);

		}
		Flag = 0 ;

	}

}

