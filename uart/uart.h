


#ifndef __UART_H
#define __UART_H 			   
#include "s3c2440_soc.h"	  
////////////////////////////////////////////////////////////////////////////////// 	 
void uart_init();
void uart_send(char x);
void puts(const char *s);

char getchar(void);

#endif

