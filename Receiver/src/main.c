#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/RCC/RCC_int.h"
#include "MCAL/UART/UART_int.h"
#include "MCAL/FMI/FMI_int.h"
#include "APP/HEXPARSER/HEXPARSER_int.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "MCAL/SYSTICK/STK_int.h"
#define SCB_VTOR  *((volatile u32*) (0xE000ED00 + 0x08))
extern USART_InitType uart2_cfg ;

u8 Flag = 1;
typedef void (*APP_Call) (void) ;
APP_Call APP = 0 ;
void (*APP)(void);
void APP_vTest(void)
{
	Flag = 0;
	//Move Vector Table
	SCB_VTOR = 0x8004000;
	//Set Address to call with Reset Handeler_ISR [startup code of Application]
	APP = *(APP_Call*)0x8004004; //startup code for APP
	APP(); //jump Reset handler [startup code]
}
void main(void)
{
	//1- system clock
	MRCC_vInit();
	//2- Enable GPIO peripheral clock for port A
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOA);
	//3- Enable USART2 peripheral clock
	MRCC_vEnableClock(RCC_APB1,RCC_EN_UART2);
	//3- Enable FDI peripheral clock
	MRCC_vEnableClock(RCC_AHB1LP,RCC_EN_FLITFLPEN);

	/////////////////////////////////////////////////////
	//4- Set Pin Mode For Pins 2 , 3 -> Alternative Function
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_MODE_ALTFUN);
	MGPIO_vSetPinOutputType(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUTTYPE_PUSHPULL);
	MGPIO_vSetPinOutputSpeed(GPIO_PORTA,GPIO_PIN2,GPIO_OUTSPEED_LOW);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN2,7);
	///////////////////////////////////////////////////////////////////////
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_MODE_ALTFUN);
	MGPIO_vSetPinOutputType(GPIO_PORTA,GPIO_PIN3,GPIO_OUTPUTTYPE_PUSHPULL);
	MGPIO_vSetPinOutputSpeed(GPIO_PORTA,GPIO_PIN3,GPIO_OUTSPEED_LOW);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN3,7);
	///////////////////////////////////////////////////////////////////////
	//5-MUSART Initialization
	uart2_cfg.BaudRate = 9600 ;
	MUSART_vInit(&uart2_cfg,USART2);
	//6-Enable USARTx
	MUSART_vEnable(USART2);
	////////////////////////////////////////////////////////////////////////
	//7- initialize SysTick
	//15s
	MSTK_vInit();
	//MSTK_vSetInterval_Single(15000000,APP_vTest);
	////////////////////////////////////////////////////////////////////////
	u8 ReceiveBuffer[100];
	u8 HEX , counter=0;
	u8 eraseFlag = 1;
	//Loop forever
	while(Flag==1)
	{


		//Read the data from UART2
		HEX = MUSART_u8ReceiveByteAsynch_(USART2,&ReceiveBuffer[counter]);


		//Bootloader
		//Stop Timer Because Application code in processing
	if ( HEX ==1 ){
           	MSTK_vStopTimer();

		//indicate the end of the Record
		if(ReceiveBuffer[counter]== '\0')
		{
	               MSTK_vStopTimer();

			if(eraseFlag==1)
			{
				//Erase the Application Code
				eraseFlag = 0;
				MFMI_vEraseAppArea();
			}
			//Parse the Record and write it on the flash
			HEXPARSER_vParseData(ReceiveBuffer);
			MUSART_vTransmitByteSynch(USART2,'K');
			//reset the counter of Buffer
			counter=0;
		}
		//indicate the end of the File
		else  counter++;
		if(ReceiveBuffer[8]=='1')
		{


			//Wait 1 second then jump to Application
			MSTK_vSetInterval_Single(1000000,APP_vTest);

		}
             }
	}
}
