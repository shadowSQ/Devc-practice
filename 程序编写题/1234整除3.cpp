#include <stdio.h>
/* 1  12  123  1234   ������Ա�3��������������*/ 
int qiu3two(int m,int n)
	{
	int x= 0;
	if(m%3==0)x=1;
		int i,count =0;
	 	for(i=m;i<n;i++)
	{
		if(x%3==0)
		{count++; 
		}
		x %= 3;
		x +=((i+2)%3); 
	}
	    if(m%3==1)
		return count;
		else 
		return count+1;
	}
	
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
	printf("%d",qiu3two(a,b));
}  
