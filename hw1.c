#include<stdio.h>
#include "hw1.h"
char reverse_string(char *str, int length)
{
char temp[30],*rev=temp;
int i,b=0;

for(i=length; i>=0;i--)
{
*(rev+b)=*(str+i);
b++;
}
*(rev+b+1)='\0';
printf("reverse string is\n %s\n",temp);
}
