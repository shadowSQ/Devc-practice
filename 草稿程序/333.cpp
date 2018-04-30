#include <stdio.h>
int choice = 0;

void check(int k,int *p,int count,int n)
{
	
	int tempn = n;
	int tempcount = count;
	if(k<count)    
    {
    	return;
    }
	
	if(k==count)    
    {
    	choice= choice+1;
    	return;
    }
    else 
    {  
    while(tempn)	
	{
    	
    
    	check(k,p,tempcount + p[n-tempn],n);
    	tempn--;
    }
    }
}


int main()
{
    int t,n,k;
    int i = 0;
    int j = 0;
    scanf("%d",&t);
    
    for(j=0;j<t;j++)
    {
    scanf("%d",&n);
    
    
    int cou[n];
    for(i=0;i<n;i++)
    {
    cou[i] = 0;
    }
    //¼ÆÊý×´Ì¬±íÖÃ0 
    
    
    scanf("%d",&k);
    int count = 0;
    int *p;
    p = new int[n];
    
    for(i=0;i<n;i++)
    {
    	scanf("%d",p+i);
    }
  //    for(i=0;i<n;i++)
//    {
 //   	printf("%d",*(p+i));
 //   }
	check(k,p,count,n);

    }
    printf("%d",(choice%100000007));
}
