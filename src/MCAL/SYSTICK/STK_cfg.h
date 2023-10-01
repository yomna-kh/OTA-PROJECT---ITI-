/*
 * STK_cfg.h
 *
 *  Created on: Aug 15, 2023
 *      Author: admin
 */

#ifndef MCAL_SYSTICK_STK_CFG_H_
#define MCAL_SYSTICK_STK_CFG_H_

/*
 * STK_AHB
 * STK_AHB_PS_8
 */
#define STK_CLK_SOURCE  STK_AHB_PS_8  // one count = 1us   10ms   10m/1u = 10 000
//ps=1 25MHZ  40nsec   10m/40ns 10 000 000
/*
 * ENABLE
 * DISABLE
 */
#define STK_INTERRUPT_EN  DISABLE

#endif /* MCAL_SYSTICK_STK_CFG_H_ */
