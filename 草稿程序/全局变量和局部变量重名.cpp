#include <stdio.h>
int a=0,b=0;
void fun()
{
	int b = 5; 
    ::b += 10;
    printf("%d %d  ",a,::b);
}
 
int main(void)
{
    fun();
    a = 10;
    printf("%d %d",a,b);
    
    return 0;
}

