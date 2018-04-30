#include <stdio.h>
  #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       
/*
从一个地点到另一个地方的最少时间
表格为六个城市到对应城市的时间表
例如：到本身的时间为0 ，而1000表示不可到达 
*/ 
	int a[6][6] = {  
	  			    {0,2,10,5,3,1000},
 			    	{1000,0,12,1000,1000,10},
 			    	{1000,1000,0,1000,7,1000},
 			    	{2,1000,1000,0,2,1000},
 			    	{4,1000,1000,1,0,1000},
 			    	{3,1000,1,1000,2,0}
 	};
int min = 100;


int dfs(int star,int lasd,int ovr)
       {
		int i;
		for(i = 0;i<=5;i++)
		{
			if(a[star][i]!=1000&&a[star][i]!=0)
			{
				if(i==ovr&&a[star][i]+lasd<=min)
				{
					min = lasd+a[star][i];
				
				}
			   	 if(i!=ovr&&a[star][i]+lasd<=min)
			   	{
			   		dfs(i,a[star][i]+lasd,ovr);	
			   	}

			}	
		}

       }


int pdfs(int star,int lasd,int ovr)
       {
		int i;
		
		for(i = 0;i<=5;i++)
		{
			if(a[star][i]!=1000&&a[star][i]!=0)
			{
				if(i==ovr&&a[star][i]+lasd<=min)
				{
					min = lasd+a[star][i];
					printf("%d",star+1);
					printf("-3\n",star+1);
					break;
						
				}
			   	if(i!=ovr&&a[star][i]+lasd<=min)
			   	{
			   	  	printf("%d-",star+1);	pdfs(i,a[star][i]+lasd,ovr);
			   	}
			   
			   	
			}
			
		}
		printf(" ",star+1);
       }

       
int main()
{	 

     dfs(4,0,2);
    	printf("\nBefore\n");
   	printf("\n%d",min);
	printf("\n");
	printf("\nAfter\n");
	
    pdfs(4,0,2);

	
	   	
     /*   printf("%d",star+1);scanf("%d",&start);
	    scanf("%d",&over);
		p = move(start,over,a);
      
*/ 
      


	
	
	
	
	
}       
