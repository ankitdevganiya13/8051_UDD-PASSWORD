#include "header.h"
void delay_ms(unsigned int ms){
	u8 i;
	for( ;ms>0;ms--){
		i=250;
		while(--i);
		i=247;
		while(--i);
	}
}