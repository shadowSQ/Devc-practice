#include <stdio.h>

/*将数字 abc def转换成   cba fed 然后相加；*/

int reverse(int a)
{
    	if(a>=70000||a<=1)
	    {
		printf("error");
		return -1;
    	} 	
	  int t = 0;
	  while(a>=10)
	{	
		t = t * 10 + a % 10;
		a = a/10;
	}
	a = t * 10 + a ;
	return a;
}
int reverseADD(int a,int b)
{
	

    return (reverse(a)+reverse(b));
}
int main()
{
	int a,b;
	scanf("%d,%d",&a,&b);
	printf("%d",reverseADD(a,b));
	return 0;
}


