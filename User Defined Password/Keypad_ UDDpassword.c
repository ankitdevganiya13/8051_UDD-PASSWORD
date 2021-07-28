/* Keypad_ UDDpassword.c */
#include <reg51.h>
#include <string.h>
#include "header.h"
sbit LEDg=P1^0;
sbit LEDr=P1^1;

void main(){
u8 P[16]={"000"}; ///default password
while(1){
u8 Q[16],S[16],j;

lcd_init();
LEDg=0;LEDr=1;
lock();
lcd_cmd(0x80);
lcd_string("ENTER PASSWORD");
input(Q);

if(strcmp(Q,P)==0){
lcd_init();
open();
lcd_cmd(0x80);
lcd_string("ACCESS GRANTED");
LEDr=0;LEDg=1;
while(keyscan()!='#');

}
				else if(strcmp(Q,"*")==0){
				lcd_init();
				lock();
				lcd_cmd(0x80);
				lcd_string("CURRENT PASSWORD");
				input(Q);

				if(strcmp(Q,P)==0){
				lcd_init();
				lock();
				lcd_cmd(0x80);
				lcd_string("NEW PASSWORD");
				input(S);

				lcd_init();
				lock();
				lcd_cmd(0x80);
				lcd_string("CONFIRM PASSWORD");
				input(Q);

				if(strcmp(Q,S)==0){ 
				//j=strlen(S);
				strcpy(P,S);
				//P[++j]=' ';
				lcd_init();
				lock();
				lcd_cmd(0x80);
				lcd_string("CHANGE");
				lcd_cmd(0xC0);
				lcd_string("SUCCESSFULL");
				while(keyscan()!='#');
				
				}
						else{
						lcd_init();
						lock();
						lcd_cmd(0x80);
						lcd_string("CHANGE");
						lcd_cmd(0xC0);
						lcd_string("UNSUCCESSFULL");
									while(keyscan()!='#');
						
						}
				}
				else
				{
				lcd_init();
				lock();
				lcd_cmd(0x80);
				lcd_string("WRONG PASSWORD");
				delay_ms(2000);
				}
				}
else{
lcd_init();
lock();
lcd_cmd(0x80);
lcd_string("ACCESS DENIED");
LEDr=0;delay_ms(250); LEDr=1;delay_ms(250);  LEDr=0;delay_ms(250);
LEDr=1;delay_ms(250); LEDr=0;delay_ms(250);  LEDr=1;delay_ms(250);
		}
	}
}
