/*******************************************************************************
* File Name: DHT22.h
*
* Version: 1.0
*
* Description:
* 	This is header file of DHT.c;
*
********************************************************************************

/* MACRO constants for sizes of DHT22 memory structures */
#define SRAMSIZE					0x04

/* DHT22 ROM register map structure */
#define RH_MSB					0x00
#define RH_LSB					0x01
#define TEMP_MSB				0x02
#define TEMP_LSB				0x03
#define CRC						0x08

/* MACROS for temperature calculation  */
#define SIGNMASK					0x80
#define SCALE_FACT			10

#include <m8c.h>

/* Function Prototypes */
void Wait_ms(WORD millis);
BOOL DHT22_Get_Temp(void);
BOOL DHT22_GetTempSign(void);
WORD DHT22_CalculateRH(void);
WORD DHT22_CalculateTemp(void);
BYTE DHT22_CalculateTempLSB(void);
BYTE DHT22_CalculateTempMSB(void);
BYTE * DHT22_GetLCDStringTemp(WORD sensorVal, BOOL sign);
//Display RH
void DHT22_Display_RH(WORD sensorVal);
/* Display temp */
void DHT22_Display_Temp(WORD sensorVal);