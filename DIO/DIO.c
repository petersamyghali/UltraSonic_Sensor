/*
 * DIO.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Lenovo
 */

#include "DIO_REG.h"
#include "../../uitils/BIT_MATH.h"
#include "DIO.h"

void DIO_SetPinDirection(u8 GoupIDcopy, u8 PinIDcopy, u8 dirIDcopy)
{
    if (dirIDcopy == INPUT)
    {
        switch (GoupIDcopy)
        {
        case GROUPA:
            CLR_BIT(DDRA_Register, PinIDcopy);
            break;
        case GROUPB:
            CLR_BIT(DDRB_Register, PinIDcopy);
            break;
        case GROUPC:
            CLR_BIT(DDRC_Register, PinIDcopy);
            break;
        case GROUPD:
            CLR_BIT(DDRD_Register, PinIDcopy);
            break;
        default:
            break;
        }
    }
    else if (dirIDcopy == OUTPUT)
    {
        switch (GoupIDcopy)
        {
        case GROUPA:
            SET_BIT(DDRA_Register, PinIDcopy);
            break;
        case GROUPB:
            SET_BIT(DDRB_Register, PinIDcopy);
            break;
        case GROUPC:
            SET_BIT(DDRC_Register, PinIDcopy);
            break;
        case GROUPD:
            SET_BIT(DDRD_Register, PinIDcopy);
            break;
        default:
            break;
        }

    }
    else
    {

    }
}

void DIO_SetPinValue(u8 GoupIDcopy, u8 PinIDcopy, u8 ValueIDcopy)
{
    if (ValueIDcopy == LOW)
    {
        switch (GoupIDcopy)
        {
        case GROUPA:
            CLR_BIT(PORTA_Register, PinIDcopy);
            break;
        case GROUPB:
            CLR_BIT(PORTB_Register, PinIDcopy);
            break;
        case GROUPC:
            CLR_BIT(PORTC_Register, PinIDcopy);
            break;
        case GROUPD:
            CLR_BIT(PORTD_Register, PinIDcopy);
            break;
        }
    }
    else if (ValueIDcopy == HIGH)
    {
        switch (GoupIDcopy)
        {
        case GROUPA:
            SET_BIT(PORTA_Register, PinIDcopy);
            break;
        case GROUPB:
            SET_BIT(PORTB_Register, PinIDcopy);
            break;
        case GROUPC:
            SET_BIT(PORTC_Register, PinIDcopy);
            break;
        case GROUPD:
            SET_BIT(PORTD_Register, PinIDcopy);
            break;
        }
    }
    else
    {
    }
}

u8 DIO_GetPinValue(u8 GoupIDcopy, u8 PinIDcopy)
{
    u8 value = 255;
    switch (GoupIDcopy)
    {
    case GROUPA:
        value = GET_BIT(PINA_Register, PinIDcopy);
        break;
    case GROUPB:
        value = GET_BIT(PINB_Register, PinIDcopy);
        break;
    case GROUPC:
        value = GET_BIT(PINC_Register, PinIDcopy);
        break;
    case GROUPD:
        value = GET_BIT(PIND_Register, PinIDcopy);
        break;
    }
    return value;
}

void DIO_SetGroupDirection(u8 GoupIDcopy, u8 DirCopy)
{
    switch (GoupIDcopy)
    {
    case GROUPA:
        DDRA_Register = DirCopy;
        break;
    case GROUPB:
        DDRB_Register = DirCopy;
        break;
    case GROUPC:
        DDRC_Register = DirCopy;
        break;
    case GROUPD:
        DDRD_Register = DirCopy;
    }
}
void DIO_SetGroupValue(u8 GoupIDcopy, u8 ValueCopy)
{
    switch (GoupIDcopy)
        {
        case GROUPA:
           PORTA_Register = ValueCopy;
            break;
        case GROUPB:
            PORTB_Register = ValueCopy;
            break;
        case GROUPC:
            PORTC_Register = ValueCopy;
            break;
        case GROUPD:
            PORTD_Register = ValueCopy;
        }
}
