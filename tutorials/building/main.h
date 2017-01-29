
main.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
#include "my_memory.h"

extern char memory[MAX_LENGTH];

/* A pretty boring main file */
int main(void){
   0:	b580      	push	{r7, lr}
   2:	af00      	add	r7, sp, #0

  clear_all(memory, MAX_LENGTH);
   4:	4b0a      	ldr	r3, [pc, #40]	; (30 <main+0x30>)
   6:	210a      	movs	r1, #10
   8:	0018      	movs	r0, r3
   a:	f7ff fffe 	bl	0 <clear_all>
  set_value(memory, 0xAA, 0);
   e:	4b08      	ldr	r3, [pc, #32]	; (30 <main+0x30>)
  10:	2200      	movs	r2, #0
  12:	21aa      	movs	r1, #170	; 0xaa
  14:	0018      	movs	r0, r3
  16:	f7ff fffe 	bl	0 <set_value>
  set_value(memory, 0xFF, 1);
  1a:	4b05      	ldr	r3, [pc, #20]	; (30 <main+0x30>)
  1c:	2201      	movs	r2, #1
  1e:	21ff      	movs	r1, #255	; 0xff
  20:	0018      	movs	r0, r3
  22:	f7ff fffe 	bl	0 <set_value>

  return 0;
  26:	2300      	movs	r3, #0
}
  28:	0018      	movs	r0, r3
  2a:	46bd      	mov	sp, r7
  2c:	bd80      	pop	{r7, pc}
  2e:	46c0      	nop			; (mov r8, r8)
  30:	00000000 	.word	0x00000000
