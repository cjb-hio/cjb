
/*LED_2 点灯

点亮LED_2,EINT5/GPF5
GPFCON 0x56000050,[11:10]设置成01
GPFDAT 0x56000054
*/

ldr r0, =0x56000050
ldr r1, =0x400
str r1, [r0]

ldr r0, =0x56000054
ldr r1, =0;
str r1, [r0]

half:
	b half




