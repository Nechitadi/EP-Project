//----------------------------------------------------------------------------
// C main line
//----------------------------------------------------------------------------

#include <m8c.h>        // part specific constants and macros
#include "PSoCAPI.h"// PSoC API definitions for all User Modules
#include "stdio.h"
#include "dht22.h"
#define PORT_1_3 PRT1DR

void main(void)
{
	WORD temp = 0;
	WORD rh = 0;
	// M8C_EnableGInt ; // Uncomment this line to enable Global Interrupts
	// Insert your main routine code here.
	static unsigned int index;
	BYTE x = 0;
	/* Initializes LCD to use the multi-line 4-bit interface */
	M8C_EnableGInt;
	LCD_Start();
	
	
	
	while (1) 
	{
		DHT22_Get_Temp();
		temp = DHT22_CalculateTemp();
		
		/*
		LCD_Position(0, 0);
		LCD_WriteData((x/100)+48);
		
		LCD_WriteData(((x/10)%10)+48);
		
		LCD_WriteData((x%10)+48);
		
		LCD_PrCString("T(hex)=");
		LCD_PrHexInt(temp);
		*/
		LCD_Position(0, 0);
		LCD_PrCString("T=");
		LCD_WriteData((temp/100)+48);
		LCD_WriteData(((temp/10)%10)+48);
		LCD_PrCString(".");
		LCD_WriteData((temp%10)+48);
		LCD_WriteData(48);
		
		rh = DHT22_CalculateRH();
		//LCD_PrHexInt(rh);
		LCD_Position(1, 0);
		LCD_PrCString("RH=");
		LCD_WriteData((rh/100)+48);
		LCD_WriteData(((rh/10)%10)+48);
		LCD_PrCString(".");
		LCD_WriteData((rh%10)+48);
		LCD_WriteData(48);
		
		/*LCD_1_PrHexInt(x);
		x++;
		PORT_1_3 ^= 0x08;*/
		for (index = 0; index < 42000; index++)
		{
			
		} 
		x++;
	}
	
}
