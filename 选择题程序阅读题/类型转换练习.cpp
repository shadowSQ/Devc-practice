

#include<stdio.h>
#include<iostream>


int main()
{

char str[] = "glad to test something";
char *p = str;
p++;
int *p1 = reinterpret_cast<int *>(p);
p1+=3;
p = reinterpret_cast<char *>(p1); 
printf("result is %s\n", p);

}

