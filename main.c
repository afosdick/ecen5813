#include<stdio.h>
#include<string.h>
#include "hw1.h"
int main()
{
char str[30];
int length=0;

printf("Enter the string\n");
gets(str);

while(str[length]!='\0')
{
length++;
}
reverse_string(str,length-1);
return 0;
}
