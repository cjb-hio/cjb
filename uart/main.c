


#include "s3c2440_soc.h"
#include "uart.h"
void delay(volatile int d)
{
	while (d--);
}

int main(void)
{

	char c;
	uart_init();
	puts("hello world\n\r");
	while(1)
	{
		c = getchar();
		if (c == '\r')
		{
			uart_send('\n');
		}

		if (c == '\n')
		{
			uart_send('\r');
		}

		uart_send(c);
	}
	return 0;
}
