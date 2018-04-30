#include <stdio.h>
// 5  2 将5转化为2进制数    后者范围0~16 
#include<math.h>
char hex[6]={'a','b','c','d','e','f' };
int zh(int d,int x)
{
    
 int temp;
 int i=0;
 int a;
    
    //如果是负数
    if(d<0)
    {
        d = -d;
        printf("-");
    }
    
    temp = d;
    
   while(temp>=x)
   {
   	temp /= x;
   	i++;
   }

while(i>=0)
{
	if(d>=pow(x, i))
	{
	a = d /pow(x, i); 
	d = d%(int)pow(x, i);	 
	if(a>9)
	{	
	printf("%c",hex[a-10]);	
	}
	else
	printf("%d",a);
	i--;
	}
	else
	{printf("0");
	i--;
	}   
}
    return 0;
}
int main()
{
    int d,x;
    int i= 0;
    int a;
    scanf("%d %d",&d,&x);
    
        zh(d,x);
    
    
    return 0;
}
