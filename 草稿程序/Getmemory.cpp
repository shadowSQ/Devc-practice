#include<stdio.h> 
#include<iostream>
using namespace std; 
void GetMemory( char **p, int num )
{
*p = (char *)malloc(num);
}

int pr(void)
{
	int a = 3;
	int b = 4;
	return a;
	
}
void Test1( void )
{
printf("%d",pr());
}

void Test( void )
{
	char *str = NULL;
	printf("%d\n",str);
	
	str = GetMemory();
	printf("%s",str);
}
int main()
{
	Test();
	
	
}
