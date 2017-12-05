/*****************************************************************************
* File Name: dht22.c
*
* Version: 1.0
*
* Description:
* DHT22 Library for PSoC 1 - Source file for DHT22 temperature sensing
*
* Owner:
* George MOIS (gicamois@yahoo.com)
*
* Hardware Dependency:
* DHT22 Digital Temperature Sensor 
*
* Code Tested With:
* 1. PSoC Designer 5.2 (SP1) - Build 2551
* 2. ImageCraft C Compiler
*
******************************************************************************/

#include "dht22.h"
#include <LCD.h>
#include <stdlib.h>
#include <string.h> 

/* Byte Array to hold Scratchpad data */
BYTE scratchpad[SRAMSIZE];

/* Byte Array to hold LCD display string */
BYTE lcdString[16];

void Wait_ms(WORD millis)
{
	while(millis)
	{
		LCD_Delay50uTimes(20); 
		millis--;
	}
}

BOOL DHT22_Get_Temp(void)
{
	unsigned int index;
	unsigned int index1;
	unsigned int i;
	BYTE startx;
	BYTE rh;
	BYTE rh1;
	BYTE t;
	BYTE t1;
	BYTE vercode;
		
		//change P2[7] to ODL - 000
		PRT2DM0 |= 0x80;
		PRT2DM1 |= 0x80;
		PRT2DM2 |= 0x80;
		
		//write 0 to P2[7] for 5ms
		PRT2DR &= ~0x80;
		Wait_ms(7);
		
		//write 1 to P2[7] for 30us
		PRT2DR |= 0x80;
		for(index = 0; index < 6; index++);
		
		//change P2[7] to High-Z - input - 010
		PRT2DM0 &= ~0x80;
		PRT2DM1 |= 0x80;
		PRT2DM2 &= ~0x80;
		
		//initialize start
		startx=0x00;
		
		//read from P2[7] start from sensor
		
		//wait for 50us and read P2[7] 
		//it should be 0
		LCD_Delay50u();
		if (~PRT2DR & 0x80){startx |= 0x01;};
		
		//wait for another 50us and read P2[7]
		//it should be 1
		LCD_Delay50u();
		if (PRT2DR & 0x80){startx |= 0x02;}
		
		if (startx==0x03){
		//while 1 on input stay
		//it's the 1 that lasts 80us
		//sent from sensor
		while((PRT2DR & 0x80)==0x80){};
		for(index = 0; index < 8; index++);

		//read the MSB BYTE of the RH Value
		for(index = 0; index < 8; index++){
		//read bit 7
		//0 signaling sending of bit
		while((PRT2DR & 0x80)==0x00){};
		//wait for 50 us
	    LCD_Delay50u();
		//shift byte to the left
		rh = rh << 1;
	    //read line
		if ((PRT2DR & 0x80)==0x80) 
			{//read 1, wait for another 50us
			rh |= 0x01;
			LCD_Delay50u();
			}
		else
			{//read 0, go to next bit
			rh &= ~0x01;
			}
		}	

		//read the LSB BYTE of the RH Value
		for(index = 0; index < 8; index++){
		//read bit 7
		//0 signaling sending of bit
		while((PRT2DR & 0x80)==0x00){};
		//wait for 50 us
	    LCD_Delay50u();
		//shift byte to the left
		rh1 = rh1 << 1;
	    //read line
		if ((PRT2DR & 0x80)==0x80) 
			{//read 1, wait for another 50us
			rh1 |= 0x01;
			LCD_Delay50u();
			}
		else
			{//read 0, go to next bit
			rh1 &= ~0x01;
			}
		}	
		
		//read the MSB BYTE of the T Value
		for(index = 0; index < 8; index++){
		//read bit 7
		//0 signaling sending of bit
		while((PRT2DR & 0x80)==0x00){};
		//wait for 50 us
	    LCD_Delay50u();
		//shift byte to the left
		t = t << 1;
	    //read line
		if ((PRT2DR & 0x80)==0x80) 
			{//read 1, wait for another 50us
			t |= 0x01;
			LCD_Delay50u();
			}
		else
			{//read 0, go to next bit
			t &= ~0x01;
			}
		}	
		
		//read the MSB BYTE of the T Value
		for(index = 0; index < 8; index++){
		//read bit 7
		//0 signaling sending of bit
		while((PRT2DR & 0x80)==0x00){};
		//wait for 50 us
	    LCD_Delay50u();
		//shift byte to the left
		t1 = t1 << 1;
	    //read line
		if ((PRT2DR & 0x80)==0x80) 
			{//read 1, wait for another 50us
			t1 |= 0x01;
			LCD_Delay50u();
			}
		else
			{//read 0, go to next bit
			t1 &= ~0x01;
			}
		}	
		
		//read the CRC
		for(index = 0; index < 8; index++){
		//read bit 7
		//0 signaling sending of bit
		while((PRT2DR & 0x80)==0x00){};
		//wait for 50 us
	    LCD_Delay50u();
		//shift byte to the left
		vercode = vercode << 1;
	    //read line
		if ((PRT2DR & 0x80)==0x80) 
			{//read 1, wait for another 50us
			vercode |= 0x01;
			LCD_Delay50u();
			}
		else
			{//read 0, go to next bit
			vercode &= ~0x01;
			}
		}	
		
		if (vercode==rh+rh1+t+t1)
		{
		scratchpad[0x00]=rh;
		scratchpad[0x01]=rh1;
		scratchpad[0x02]=t;
		scratchpad[0x03]=t1;
		return 1;
		}
		}

		return 0;
}

/* Get sign of temperature from the Scratchpad data */
BOOL DHT22_GetTempSign(void)
{
	/* if minus modify scratchpad, keep minus and rewrtie temp value*/
	if ((scratchpad[TEMP_MSB] & SIGNMASK)==0x80)
	{
		scratchpad[TEMP_MSB] &=~SIGNMASK;
	}
	/* DHT22_GetTempSign returns:
	 1 = Negative (<  0 C)
	 0 = Positive (>= 0 C) */
	return scratchpad[TEMP_MSB] & SIGNMASK;
}

/* Calculate temperature value from the readback data */
WORD DHT22_CalculateTemp(void)
{
	WORD calcTemp;
	BYTE tempVal0 = scratchpad[TEMP_LSB];
	BYTE tempVal1 = scratchpad[TEMP_MSB];

	/* Calculate temperature
	   the resultant value is multiplied by SCALE_FACT to preserve decimal digits */
	
	calcTemp = (SCALE_FACT * tempVal1) >> 1;
	calcTemp = (tempVal0 | (tempVal1 << 8));

	return calcTemp;
}

/* Calculate temperature value from the readback data */
WORD DHT22_CalculateRH(void)
{
	WORD calcRH;
	BYTE RHVal0 = scratchpad[RH_LSB];
	BYTE RHVal1 = scratchpad[RH_MSB];

	/* Calculate temperature
	   the resultant value is multiplied by SCALE_FACT to preserve decimal digits */
	
	calcRH = RHVal0 | (RHVal1 << 8);
	
	return calcRH;
}

/* Display temp */
void DHT22_Display_Temp(WORD sensorVal)
{
	char tmp[3];
	LCD_PrCString("T=");
	
	//if sign minus then print "-"
	if (DHT22_GetTempSign() == 1) {LCD_PrCString("-");} 
	
	itoa(tmp,sensorVal/10,10);
	LCD_PrString(tmp);
	LCD_PrCString(".");
	itoa(tmp,sensorVal%10,10);
	LCD_PrString(tmp);
	LCD_PrCString("C");
}

/* Display RH */
void DHT22_Display_RH(WORD sensorVal)
{
	char tmp[3];
	LCD_PrCString("RH=");
	itoa(tmp,sensorVal/10,10);
	LCD_PrString(tmp);
	LCD_PrCString(".");
	itoa(tmp,sensorVal%10,10);
	LCD_PrString(tmp);
}