/*
 * INT.c

 *
 *  Created on: May 26, 2022
 *      Author: Peter
 */
#include "INT.h"
#include "../../HAL/includes.h"
void INT0_Init(void){
	SET_BIT(GICR,INT0);
	// will be generated at the low level of the INT0
}
void Enable_Ex_Interrupt1(void){
	GICR |= (1<<INT1);// Enable INT1 interrupts.
	MCUCR|=(1<<ISC10);	// Trigger INT1 on any logic change.
}
