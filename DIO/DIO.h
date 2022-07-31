/*
 * DIO.h
 *
 *  Created on: Aug 23, 2019
 *      Author: Lenovo
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_
#include "../../uitils/STD_TYPES.h"


#define GROUPA 0
#define GROUPB 1
#define GROUPC 2
#define GROUPD 3


#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7

#define INPUT 0
#define OUTPUT 1


#define LOW  0
#define HIGH 1

void DIO_SetPinDirection(unsigned char GoupIDcopy, unsigned char PinIDcopy, unsigned char dirIDcopy);
void DIO_SetPinValue(unsigned char GoupIDcopy, unsigned char PinIDcopy, unsigned char ValueIDcopy);
unsigned char DIO_GetPinValue(unsigned char GoupIDcopy, unsigned char PinIDcopy);
void DIO_SetGroupDirection(unsigned char GoupIDcopy, unsigned char DirCopy);
void DIO_SetGroupValue(unsigned char GoupIDcopy, unsigned char ValueCopy);

#endif /* MCAL_DIO_DIO_H_ */
