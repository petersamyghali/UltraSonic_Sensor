/*
 * timer.c
 *
 *  Created on: Mar 21, 2022
 *      Author: Peter
 */
#include "../../HAL/includes.h"
void Timer2_Init(void)
{
	TCCR2=0x00;// (stop counting)
	TCCR2=0x01;//no prescaler (1 tick =125 nano_Second)
	TCNT2=0x00;//reset the timer counter
	TIMSK|=(1<<TOIE2);/*Enable timer2 interrupt flag*/
}
void Init_Phasecorrect_Timer_0(void)
{
	TCCR0 |=  (1<<0);
	TCCR0 &= ~(1<<1);
	TCCR0 |=  (1<<2);
	TCCR0 &= ~(1<<3);
	TCCR0 |=  (1<<4);
	TCCR0 |=  (1<<5);
	TCCR0 |=  (1<<6);
	TCCR0 &= ~(1<<7);

	TCCR0 = 0b01110101;  									//phase correct mode,1024 prescaling,inverted mode
	DIO_SetPinDirection(GROUPB,PIN_3,1); 				  // set OC0 as output pin (pinB 3)

}
void Init_PWM_Timer1(void){
	TCCR1A |= (1<<COM1A1)| (1<<WGM11) ;				 			 //FAST PWM ,TOP IS ICR1, CLEAR ON COMPARE MATCH
	TCCR1B |= (1<<WGM13)| (1<<WGM12)| (1<<CS11)|(1<<CS10);    	  // CLOCK PRESCALAR BY 64
	ICR1 = 2499;					            			      // FREQUENCY IS 50 HZ
}
