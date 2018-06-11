
/*启动文件

WTCON 0x53000000
[0] 1:开启 0:关闭
*/

.text
.global _start
_start:
/*
//关闭看门狗
ldr r0, =0x53000000
ldr r1, =0x0
str r1, [r0]
*/
//设置sp
ldr sp, =4*1024

bl main

half:
	b half




