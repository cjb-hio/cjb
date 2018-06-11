/*
led灯输出 GPF4/GPF5/GPF6
按键输入	  GPF0/GPF2/GPG3
*/

#include "s3c2440_soc.h"
int main()
{
	//配置io口功能
	GPFCON &= ~(3<<8 | 3<<10 | 3<<12);
	GPFCON |= 1<<8 | 1<<10 | 1<<12;

	GPFCON &= ~(3<<0 | 3<<4);//配置输入引脚
	GPGCON &= ~(3<<6);//配置输入引脚
	
	//如果按下则点灯
	while(1)
	{
		if(GPFDAT & (1<<0))//输入为高，表示未按下
		{
			GPFDAT |=1<<4;
		}else{//表示按下
			GPFDAT &=~(1<<4);
		}

		if(GPFDAT & (1<<2))//输入为高，表示未按下
		{
			GPFDAT |=1<<5;
		}else{//表示按下
			GPFDAT &=~(1<<5);
		}

		if(GPGDAT & (1<<3))//输入为高，表示未按下
		{
			GPFDAT |=1<<6;
		}else{//表示按下
			GPFDAT &=~(1<<6);
		}
	}

	

	return 0;
}

