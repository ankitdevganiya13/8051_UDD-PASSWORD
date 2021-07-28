/* lcd8bit_driver.c */
#include <reg51.h>
#include "header.h"

//#include <stdio.h>
sbit RS=P3^4;
sbit RW=P3^5;
sbit EN=P3^6;
#define LCD_PORT P0

void lcd_cmd(u8 cmd){
	LCD_PORT=cmd;
	RS=0;
	RW=0;
	EN=1;
	delay_ms(2);
	EN=0;
}
void lcd_data(u8 d){
	LCD_PORT=d;
	RS=1;
	RW=0;
	EN=1;
	delay_ms(2);
	EN=0;
}
void lcd_init(void){
	lcd_cmd(0x2);
	lcd_cmd(0x38);
	lcd_cmd(0xE);
	lcd_cmd(0x1);
}	
void lcd_string(s8 *p){
	while(*p!=0)
	{
		lcd_data(*p);	
		p++;
	}
}
u8 string_len(s8 *p){
	u8 l;
	for(l=0;p[l];l++);
	return l;
}
void second(void){
	u16 i;
	for(i=0;i<60;i++){
	lcd_cmd(0x86);
		lcd_data(i/10+48);
		lcd_data(i%10+48);
		delay_ms(10);
	}
}
void minute(void){
	u16 i;
	for(i=0;i<60;i++){
	lcd_cmd(0x83);
		lcd_data(i/10+48);
		lcd_data(i%10+48);
		delay_ms(10);
		second();
	}
}	
void hour(void){
	u16 i;
	for(i=0;i<60;i++){
	lcd_cmd(0x80);
		lcd_data(i/10+48);
		lcd_data(i%10+48);
		delay_ms(10);
		minute();
	}
}	

code u8 arr[]={0X1C,0x12,0x11,0x1D,0x09,0x10,0x0E,0x00};
void cgram_init(void){
	u8 i;
	lcd_cmd(0x40);
	for(i=0;i<8;i++)
	lcd_data(arr[i]);
	lcd_cmd(0x80);
}
////integer function
void lcd_integer(u16 n)
{
      u8 p[8],t;
    int i=0, c=0;
		if(n<0)
	{
		lcd_data('-');
		n=-n;
	}
	for(;n;n=n/10,i++)
	{
	t=n%10+48;
	p[i]=t;
		c++;
	}
	
	for(i=c-1;i>=0;i--)
	{
	lcd_data(p[i]);
	}
	
}

void lcd_float(float n)
{
    
	int i,c=0;
	i=n;
	lcd_integer(i);
	lcd_data('.');
	i=(n-i)*100;
	lcd_integer(i); 
} 

//void lcd_Shift_Right(void){ 
//int j;
//for(j=0;j{lcd_cmd(0x1C);delay_ms(100);}
//}

//void lcd_Shift_Left(void){ 
//int k;
//for(k=0;k{lcd_cmd(0x18);delay_ms(100);}
//}

