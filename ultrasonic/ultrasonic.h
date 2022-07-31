#ifndef _ULTRA_H_
#define _ULTRA_H_

#define   TRIGER_DDR    GROUPD
#define   ECHO_DDR      GROUPD
#define   TRIGER        PIN_4
#define   ECHO          PIN_3

void Ultrasonic_Init(void);// to initialize the echo and tiger pins
void Ultrasonic_Trigger(void);// to tiger the tiger pin to start the sensor and calculating the distance
uint32_t Get_Distance (void);
void UltraSoic_MainFunction (void );
#endif
