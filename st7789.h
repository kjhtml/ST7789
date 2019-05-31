#include <SPI.h>
#define TFT_CS 10
#define TFT_RST 8
#define TFT_DC 9

//**********write register command***********//
void LCD_WriteCommand(unsigned short c)
{
digitalWrite(TFT_DC, LOW);
SPI.transfer(c);
}
//***************write  data****************// 
void LCD_WriteData(unsigned short dat)
{
digitalWrite(TFT_DC, HIGH);
SPI.transfer(dat);
}

void LCD_WriteDatas(unsigned short R,unsigned short G,unsigned short B)
{
digitalWrite(TFT_DC, HIGH);
SPI.transfer(R);
SPI.transfer(G);
SPI.transfer(B);
}
//初始化

void LCD_Init(){  
digitalWrite(TFT_CS, LOW);
digitalWrite(TFT_RST, HIGH);
delay (100);//Delay 1ms
digitalWrite(TFT_RST, LOW);
delay (100);//Delay 1ms
digitalWrite(TFT_RST, HIGH);
delay (300);//Delay 120ms
//--------------------------------End ST7735S Reset Sequence ---------------------------------------//
LCD_WriteCommand(0x11); //Sleep out
delay(120); //Delay 120ms
LCD_WriteCommand(0x21); 
//------------------------------------ST7735S Frame rate-------------------------------------------------//
LCD_WriteCommand(0xB1); //Frame rate 80Hz
LCD_WriteData(0x05);
LCD_WriteData(0x3a);
LCD_WriteData(0x3a);
LCD_WriteCommand(0xB2); //Frame rate 80Hz
LCD_WriteData(0x05);
LCD_WriteData(0x3a);
LCD_WriteData(0x3a);
LCD_WriteCommand(0xB3); //Frame rate 80Hz
LCD_WriteData(0x05);
LCD_WriteData(0x3a);
LCD_WriteData(0x3a);
LCD_WriteData(0x05);
LCD_WriteData(0x3a);
LCD_WriteData(0x3a);
//------------------------------------End ST7735S Frame rate-------------------------------------------//
LCD_WriteCommand(0xB4); //Dot inversion
LCD_WriteData(0x03);
//------------------------------------ST7735S Power Sequence-----------------------------------------//
LCD_WriteCommand(0xC0);
LCD_WriteData(0x62);
LCD_WriteData(0x02);
LCD_WriteData(0x04);
LCD_WriteCommand(0xC1);
LCD_WriteData(0xC0);
LCD_WriteCommand(0xC2);
LCD_WriteData(0x0D);
LCD_WriteData(0x00);
LCD_WriteCommand(0xC3);
LCD_WriteData(0x8D);
LCD_WriteData(0x6A);
LCD_WriteCommand(0xC4);
LCD_WriteData(0x8D);
LCD_WriteData(0xEE);
//---------------------------------End ST7735S Power Sequence---------------------------------------//
LCD_WriteCommand(0xC5); //VCOM
LCD_WriteData(0x0e);
//------------------------------------ST7735S Gamma Sequence-----------------------------------------//
LCD_WriteCommand(0XE0);
LCD_WriteData(0x10);
LCD_WriteData(0x0e);
LCD_WriteData(0x02);
LCD_WriteData(0x03);
LCD_WriteData(0x0e);
LCD_WriteData(0x07);
LCD_WriteData(0x02);
LCD_WriteData(0x07);
LCD_WriteData(0x0a);
LCD_WriteData(0x12);
LCD_WriteData(0x27);
LCD_WriteData(0x37);
LCD_WriteData(0x00);
LCD_WriteData(0x0d);
LCD_WriteData(0x0e);
LCD_WriteData(0x10);
LCD_WriteCommand(0XE1);
LCD_WriteData(0x10);
LCD_WriteData(0x0e);
LCD_WriteData(0x03);
LCD_WriteData(0x03);
LCD_WriteData(0x0f);
LCD_WriteData(0x06);
LCD_WriteData(0x02);
LCD_WriteData(0x08);
LCD_WriteData(0x0a);
LCD_WriteData(0x13);
LCD_WriteData(0x26);
LCD_WriteData(0x36);
LCD_WriteData(0x00);
LCD_WriteData(0x0d);
LCD_WriteData(0x0e);
LCD_WriteData(0x10);
//------------------------------------End ST7735S Gamma Sequence-----------------------------------------//
LCD_WriteCommand(0x3A);//05=65k mode;06=rgb666
LCD_WriteData(0x06);
LCD_WriteCommand(0x36); //MX, MY, RGB mode
LCD_WriteData(0x68);
LCD_WriteCommand(0x29);//Display on
}

void Lcd_SetRegion(unsigned int x_start,unsigned int y_start,unsigned int x_end,unsigned int y_end)
{  
  LCD_WriteCommand(0x2a);
  LCD_WriteData(0x00);
  LCD_WriteData(x_start);
  LCD_WriteData(0x00);
  LCD_WriteData(x_end);

  LCD_WriteCommand(0x2b);
  LCD_WriteData(0x00);
  LCD_WriteData(y_start+0x1A);
  LCD_WriteData(0x00);
  LCD_WriteData(y_end+0x1A); 
  LCD_WriteCommand(0x2c);
}
