#include <stdio.h>
int shenzi(int n)
{
	
	int i,j;
	int maxs=0,mult=0;
	if(n<2)
	return 0;
	if(n==2)
	return 1;
	if(n==3)
	return 2;
	
	
	int h[100]={0};
	h[0] = 0; 
	h[1] = 1; 
	h[2] = 2; 
	h[3] = 3; 
	
	for(i = 4;i<=n;i++)
	{
		maxs = 0;
		for(j=1;j<=i/2+1;j++)
		{
			mult = h[j]*h[i-j];
			if(maxs<mult)
			maxs = mult;
			
		}
		h[i]=maxs;
		
	}
	printf("%d",h[n]);
}


int main(){

	int n;
	scanf("%d",&n);
	shenzi(n);
	
}
