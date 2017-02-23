#include <stdint.h>
#include <stdio.h>

#define SET_EQUAL(a,b) (a=(uint8_t)b)
#define SQUARE(a) (a*a)
#define BASE 16
#define OFFSET 10+BASE

void main(){

  int32_t foo = -12;
  int8_t var = OFFSET*2;
  uint8_t bar = 0;
  uint8_t x = 3, y=0;

  y = SQUARE(x++);
  SET_EQUAL(bar, foo);
  printf("bar %d \n\r",bar);
  printf("var %d \n\r",var);
  printf("y=%d ,x=%d \n\r",y,x);

 return;
}

