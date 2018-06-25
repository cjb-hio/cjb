/*uart���ڳ���
**���ڵĿ��ļ�
**
*/

#include "s3c2440_soc.h"
#include "uart.h"

void uart_init()
{
	
	//TXD0,RXD0:usbת����
	//GPH2,GPH3
	//����io����
	
	/* ��������Ϊuart */
	GPHCON &= ~((3<<4) | (3<<6));
	GPHCON |=  ((2<<4) | (2<<6));
	//������������
	GPHUP &= ~((1<<2) | (1<<3));  /* ʹ���ڲ����� */
	//����uart�Ĵ���
		
	//ULCON0���ô��ڲ��� ��У�飬1ֹͣλ��8�ֽڣ�
	//ULCON0=0x03
	ULCON0=0x03;
	//UCON0���ã�	ʱ��ԴPCLK
	UCON0=0x0005;
	//UBRDIVn = (int)( UART clock / ( buad rate x 16) ) �C1,26,115200Ƶ��
	UBRDIV0=26;
}

//UTRSTAT0״̬�Ĵ���
//[0]:Receive buffer data [1]:Transmit buffer empty [2]:Transmitter empty
void uart_send(char x)
{
	while((UTRSTAT0 &(0x01<<1))==0)
	{
		
	}
	UTXH0=x;
}
void puts(const char *s)
{
	while (*s)
	{
		uart_send(*s);
		s++;
	}
}
char getchar(void)
{
	while (!(UTRSTAT0 & (1<<0)));
	return URXH0;
}


