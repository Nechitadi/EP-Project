Project:      output/TASProject
Build Number: 0
Date:         Wed Nov 29 21:05:21 2017
Compiler:     ICCM8C
Version:      7.05.00


Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             lit   01A0   008A =    138. bytes (rel,con,rom,lit)

       Addr  Global Symbol
      -----  --------------------------------
       01B6  LoadConfigTBL_tasproject_Bank0
       0205  LoadConfigTBL_tasproject_Bank1
       022A  __lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                        func_lit   022A   0002 =      2. bytes (rel,con,rom,proclab)

       Addr  Global Symbol
      -----  --------------------------------
       022A  __func_lit_start
       022C  __func_lit_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     psoc_config   022C   0170 =    368. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       022C  LoadConfigTBL_tasproject_Ordered
       0331  _LoadConfigInit
       0331  LoadConfigInit
       0341  _LoadConfig_tasproject
       0341  LoadConfig_tasproject
       039C  __psoc_config_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                     UserModules   039C   01B7 =    439. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       039C  _LCD_PrCString
       039C  LCD_PrCString
       03AE  LCD_HEX_STR
       03BE  LCD_PrHexByte
       03BE  _LCD_PrHexByte
       03D1  _LCD_PrHexInt
       03D1  LCD_PrHexInt
       03D8  _LCD_PrString
       03D8  LCD_PrString
       03EA  _LCD_Write_Data
       03EA  LCD_Write_Data
       03EA  LCD_WriteData
       03EA  _LCD_WriteData
       03FE  LCD_Control
       03FE  _LCD_Control
       04AE  _LCD_Start
       04AE  _LCD_Init
       04AE  LCD_Init
       04AE  LCD_Start
       051D  LCD_ROW_OFFSET
       0521  LCD_Position
       0521  _LCD_Position
       0531  LCD_Delay50uTimes
       0531  _LCD_Delay50uTimes
       0537  LCD_Delay50u_Table
       053F  _LCD_Delay50u
       053F  LCD_Delay50u
       0553  __UserModules_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0553   0856 =   2134. bytes (rel,con,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0553  _Wait_ms
       0553  __text_start
       056F  _DHT22_Get_Temp
       07A3  _DHT22_GetTempSign
       07BC  _DHT22_CalculateTemp
       081E  _DHT22_CalculateRH
       0857  _DHT22_Display_Temp
       0902  _DHT22_Display_RH
       098E  _main
       0BD0  _itoa
       0DA9  __xidata_start
       0DA9  __text_end
       0DB3  __xidata_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             TOP   0000   0143 =    323. bytes (abs,ovr,rom,code)

       Addr  Global Symbol
      -----  --------------------------------
       0068  __Start
       0140  _bGetPowerSetting
       0140  bGetPowerSetting

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                    InterruptRAM   0000   0003 =      3. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  _NO_SHADOW
       0000  Port_2_Data_SHADE
       0000  NO_SHADOW
       0000  _Port_2_Data_SHADE
       0001  _Port_2_DriveMode_0_SHADE
       0001  Port_2_DriveMode_0_SHADE
       0002  _Port_2_DriveMode_1_SHADE
       0002  Port_2_DriveMode_1_SHADE

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
               virtual_registers   0013   0007 =      7. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0013  __rZ
       0014  __rY
       0015  __rX
       0016  __r3
       0017  __r2
       0018  __r1
       0019  __r0

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0000   0016 =     22. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0000  __data_start
       0003  _lcdString
       001A  _scratchpad

Files Linked      [ module(s) ]

./obj/boot.o	[ boot.asm ]
obj/dht22.o	[ dht22.c ]
obj/main.o	[ main.c ]
<library>	[ psocconfigtbl.asm, psocconfig.asm, lcd.asm, rZ.asm, rY.asm, rX.asm, r3.asm, r2.asm, r1.asm, r0.asm ]
[ divmodu_16x16_16_util.asm, i_div16_block_util.asm, mul16_util.asm, itoa.s ]

Area Definitions

-blit:0x1a0.0x7fff
-bdata:0.0x6ff
-BInterruptRAM:0	allocated at: 0
-Bvirtual_registers	allocated at: 0x13
-Btasproject_RAM
-rwh:SSCParmBlk:0xf7.0xff

