/*
led����� GPF4/GPF5/GPF6
��������	  GPF0/GPF2/GPG3
*/

#include "s3c2440_soc.h"
int main()
{
	//����io�ڹ���
	GPFCON &= ~(3<<8 | 3<<10 | 3<<12);
	GPFCON |= 1<<8 | 1<<10 | 1<<12;

	GPFCON &= ~(3<<0 | 3<<4);//������������
	GPGCON &= ~(3<<6);//������������
	
	//�����������
	while(1)
	{
		if(GPFDAT & (1<<0))//����Ϊ�ߣ���ʾδ����
		{
			GPFDAT |=1<<4;
		}else{//��ʾ����
			GPFDAT &=~(1<<4);
		}

		if(GPFDAT & (1<<2))//����Ϊ�ߣ���ʾδ����
		{
			GPFDAT |=1<<5;
		}else{//��ʾ����
			GPFDAT &=~(1<<5);
		}

		if(GPGDAT & (1<<3))//����Ϊ�ߣ���ʾδ����
		{
			GPFDAT |=1<<6;
		}else{//��ʾ����
			GPFDAT &=~(1<<6);
		}
	}

	

	return 0;
}

