#include <Arduino.h>
#include "7789.h"
#include "sony.h"
//------------------
void lcd_pic(unsigned int x_start,unsigned int y_start,unsigned int x_end,unsigned int y_end){
  Lcd_SetRegion(10,80,40,140);
  for(int i=0;i<2800;i++){
    for(int j=0;j<=80;j++){
      LCD_WriteData(i%256);
      LCD_WriteData((i+80)%256);
      LCD_WriteData((i+160)%256);
    }
  }
}
void setup() {
  // put your setup code here, to run once:
pinMode(TFT_CS,OUTPUT);
pinMode(TFT_RST,OUTPUT);
pinMode(TFT_DC,OUTPUT); 
digitalWrite(TFT_CS, HIGH);   //SPI内部逻辑复位
SPI.begin();
digitalWrite(TFT_CS, LOW);   //SPI内部逻辑复位
LCD_Init();
Lcd_SetRegion(0,0,160,80);// 黑色背景
for(int i=0;i<=80;i++){
  for(int j=0;j<=160;j++){
    LCD_WriteDatas(255,255,255);
  }
}
}
void loop() {
  // put your main code here, to run repeatedly:
int h;
Lcd_SetRegion(0,0,15,15);// 黑色背景
for(int i=0;i<=256;i++){
    h=str[1][i/8]>>(i%8)&1;
    if(h==1){
    LCD_WriteDatas(255,255,255);}else{      
    LCD_WriteDatas(0,0,0);
  }
}

}
