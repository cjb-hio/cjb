/*uart串口程序
**串口的库文件
**
*/

#include "s3c2440_soc.h"
#include "uart.h"

void uart_init()
{
	
	//TXD0,RXD0:usb转串口
	//GPH2,GPH3
	//配置io引脚
	
	/* 设置配置为uart */
	GPHCON &= ~((3<<4) | (3<<6));
	GPHCON |=  ((2<<4) | (2<<6));
	//配置上拉电阻
	GPHUP &= ~((1<<2) | (1<<3));  /* 使能内部上拉 */
	//配置uart寄存器
		
	//ULCON0设置串口参数 无校验，1停止位，8字节，
	//ULCON0=0x03
	ULCON0=0x03;
	//UCON0设置，	时钟源PCLK
	UCON0=0x0005;
	//UBRDIVn = (int)( UART clock / ( buad rate x 16) ) –1,26,115200频率
	UBRDIV0=26;
}

//UTRSTAT0状态寄存器
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


