/* UDD_driver.c */
#include <reg51.h>
#include "header.h"
#include <string.h>

//// FUNCTIONS FOR LOCK image on LCD////
void lock(void){
lcd_cmd(72);
lcd_data(0);lcd_data(14);lcd_data(10);lcd_data(10);lcd_data(31);
lcd_data(27);lcd_data(31);lcd_cmd(0xCF);lcd_data(1);
}
void open(void){
lcd_cmd(72);lcd_data(14);lcd_data(10);lcd_data(2);
lcd_data(2);lcd_data(31);lcd_data(27);lcd_data(31);lcd_cmd(0xCF);lcd_data(1);
}

//// FUNCTION INPUTTING VALES FROM USERS AND STORING THEM TO AN ARRAY////
void input(s8 arr[]){ 
u8 i=0,k=0,N[16];
lcd_cmd(0xC0);
while(k!='#'){
k=keyscan();
if(k && k!='#'){
N[i++]=k;
	lcd_data(k);
//lcd_data('*');
	}
}
N[i]='\0';
strcpy(arr,N);

}
