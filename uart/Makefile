all:
	arm-linux-gcc -c -o main.o main.c
	arm-linux-gcc -c -o start.o start.S
	arm-linux-gcc -c -o uart.o uart.c
	arm-linux-ld -Ttext 0 start.o main.o uart.o -o demo.elf
	arm-linux-objcopy -O binary -S demo.elf demo.bin
	arm-linux-objdump -D demo.elf > demo.dis
clean:
	rm *.bin *.o *.elf *.dis
	
