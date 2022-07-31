#include "../includes.h"
uint8_t sensor_working=0;
uint8_t rising_edge=0;
uint32_t timer_counter=0;
static uint32_t Distance;
uint8_t distance_str[10];
void Ultrasonic_Init(void)
{
	DIO_SetPinDirection(TRIGER_DDR,
			TRIGER,
			OUTPUT);		/*Triger pin as output*/
	DIO_SetPinDirection(ECHO_DDR,
			ECHO,
			INPUT);
	DIO_SetPinValue(ECHO_DDR,
			ECHO,
			HIGH);			/*Echo pin as input (Pulled_up)*/
	Enable_Ex_Interrupt1();							// for the echo pin
	Timer2_Init();									// to know how many overflows

}

void Ultrasonic_Trigger(void)
{
	if(!sensor_working)
	{
		DIO_SetPinDirection(TRIGER_DDR,TRIGER,HIGH);/*15 us pulse in the triger pin to enable it so that it sends a pulse and receive it by the echo pin*/
		_delay_us(15);
		DIO_SetPinDirection(TRIGER_DDR,TRIGER,LOW);	//low again
		sensor_working=1;
	}
}
ISR(INT1_vect)
{
	if(sensor_working==1)
	{
		//if the sensor is working (the sensor has been triggered)
		if(rising_edge==0)
		{			// if rising edge
			TCNT2=0x00;				//reset the timer counter
			rising_edge=1;
			timer_counter=0;
		}
		else
		{						//overflows times *(2^8)+ the value in the counter register
			Distance=(timer_counter*256+TCNT2)/466;/*466=(34300*.125*10^-6)/2)to return the distance in CM*/
			//			LCD_GoTo_XY(1,0);
			//			itoa(Distance,distance_str,10);
			//			strcat(distance_str, " cm ");
			//			LCD_Write_Word(distance_str);
			timer_counter=0;		// after calculating the distance reset the overflows times
			rising_edge=0;			// now the sensor is not working
		}
	}
}
ISR(TIMER2_OVF_vect)
{				/*a counter to know how many overflows has occured*/
	timer_counter++;				//add one to the overflows counter
	if(timer_counter >730){			// if more than 730 overflows happend (max distance is 4M )
		TCNT2=0x00;					//reset the timer counter
		sensor_working=0;			// now the sensor is not working
		rising_edge=0;				//rising edge is reseted
		timer_counter=0;			// overflows time now is equal to zero
	}
}

uint32_t Get_Distance (void){
	return Distance;
}
