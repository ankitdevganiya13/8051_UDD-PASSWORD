/*  keypad_driver.c */
#include <reg51.h>
#include "header.h"
sbit R0=P2^0;
sbit R1=P2^1;
sbit R2=P2^2;
sbit R3=P2^3;
sbit C0=P2^4;
sbit C1=P2^5;
sbit C2=P2^6;
sbit C3=P2^7;
//lookuptable declaration
code u8 kpd_ltb[4][4]={'7','8','9','A',
                       '4','5','6','B',
                       '1','2','3','C',
											 '*','0','#','D'};

u8 keyscan(void){
 u8 row_num,col_num,sw_num;
R0=R1=R2=R3=0;
C0=C1=C2=C3=1;
while((C0&C1&C2&C3)==1);//waiting for SW press
	delay_ms(50);//avoid key bouncing
//finding out row
//check row 0	
R0=0;
R1=R2=R3=1;	
if((C0&C1&C2&C3)==0){
row_num=0;
	goto col_check;
}
//finding out row
//check row 1	
R1=0;
R0=R2=R3=1;	
if((C0&C1&C2&C3)==0){
row_num=1;
	goto col_check;
}
//finding out row
//check row 2
R2=0;
R0=R1=R3=1;	
if((C0&C1&C2&C3)==0){
row_num=2;
	goto col_check;
}
//finding out row
//check row 3
R3=0;
R0=R1=R2=1;	
if((C0&C1&C2&C3)==0){
row_num=3;
	goto col_check;
}
col_check:
if(C0==0)
col_num=0;
else if(C1==0)
	col_num=1;
else if(C2==0)
	col_num=2;
else if(C3==0)
	col_num=3;

while((C0&C1&C2&C3)==0);//waiting for SW release
sw_num=kpd_ltb[row_num][col_num];
return sw_num;
}
	
	
	