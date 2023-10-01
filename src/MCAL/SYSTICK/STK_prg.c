/*
 * STK_prg.c
 *
 *  Created on: Aug 15, 2023
 *      Author: admin
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "STK_int.h"
#include "STK_prv.h"
#include "STK_cfg.h"


void (*G_vCallBack) (void) = 0 ;
u8 G_u8Flag ;
void MSTK_vInit(void)
{
	/*Clock source*/
#if STK_CLK_SOURCE == STK_AHB
	SET_BIT(STK->CTRL,CLKSOURCE);
#elif STK_CLK_SOURCE == STK_AHB_PS_8
	CLR_BIT(STK->CTRL,CLKSOURCE);
#endif
	/*2- Interrupt enable Disable*/
#if STK_INTERRUPT_EN == ENABLE
	SET_BIT(STK->CTRL,TICKINT);
#else
	CLR_BIT(STK->CTRL,TICKINT);
#endif
}

void MSTK_vStopTimer(void)
{
	STK->VAL = 0 ;
	CLR_BIT(STK->CTRL,STK_ENABLE);
}

void MSTK_vStartTimer(void)
{
	SET_BIT(STK->CTRL,STK_ENABLE);
}
void  MSTK_vSetBusyWait(u32 A_u32Tick)
{
	/*1- reset Timer value*/
	STK->VAL = 0 ;
	/*2- load timer with value*/
	STK->LOAD = A_u32Tick;
	/*3- Start the timer*/
	MSTK_vStartTimer();
	/*4- polling */
	while(GET_BIT(STK->CTRL,COUNTFLAG)!=1){}
	/*5- Stop the timer  */
	MSTK_vStopTimer();
}


void MSTK_vSetInterval_Single  (u32 A_u32Tick , void(*CallBackFun)(void))
{
	/*0- set callBack Function */
	G_vCallBack = CallBackFun ;//100
	G_u8Flag = SINGLE ;
	/*1- reset Timer value*/
	STK->VAL = 0 ;
	/*2- load timer with value*/
	STK->LOAD = A_u32Tick;
	/*3- Start the timer*/
	MSTK_vStartTimer();

}
void MSTK_vSetInterval_Periodic(u32 A_u32Tick , void(*CallBackFun)(void))
{
	/*0- set callBack Function */
	G_vCallBack = CallBackFun ;//100
	G_u8Flag = PERIODIC;
	/*1- reset Timer value*/
	STK->VAL = 0 ;
	/*2- load timer with value*/
	STK->LOAD = A_u32Tick;
	/*3- Start the timer*/
	MSTK_vStartTimer();
}

u32 MSTK_u32GetElapsedTime(void)
{
 return  (STK->LOAD-STK->VAL) ;
}
u32 MSTK_u32GetRemainingTime(void)
{
	return  (STK->VAL) ;
}

void  SysTick_Handler (void){
	u8 L_u8ClearFlag ;
	if(G_vCallBack != 0)
	{
		G_vCallBack();

	}
	if(G_u8Flag == SINGLE)
	{
		G_u8Flag = PERIODIC;
		MSTK_vStopTimer();
	}
	L_u8ClearFlag = GET_BIT(STK->CTRL,COUNTFLAG) ;
}




