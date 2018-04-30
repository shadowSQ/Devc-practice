#include <stdio.h>
#include<string.h>

int zh(char *p,int n)
{
    int i,j=n;
    int s=0;
    int k = n;
    int t;  
     if(*p=='+')
    {p++;k--;j--;
    } 
     if(*p=='-') 
    {
    printf("-");
	p++;k--;j--;
    } 
    for(i=0;i<k;i++)
    { 
	t = (*p-48);
    	    if (n==1)
 			  {s =s+ *p-48;printf("%d",s);return 0;
 			  } 
    	
    	 while(--j)
    	 
    {
    	 t = t*10;
    }
    s += t;
    
    p++;
    j=k-i-1;
    n--;
    	
    }
	printf("%d",s);
}

int main()
{
    char s[]={};
    
    scanf("%s",&s);

    zh(s,strlen(s));
    

}
