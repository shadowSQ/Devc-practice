#include <stdio.h>
//80%通过率，不知道为啥，还需要看看别人的哦 。 
  struct Pre
    {
        int a;
        int b;
    };
int  eatorder(Pre *p,int m,int n)

{
	int eatnow=0;
    int flag=0;
    int flaglast=0;
	if(n==0)
	return 0;
	int i,j;
	
  //找到一定可以吃的那个菜品，思路为右侧列有，但是左侧列没有的那一道菜，一定是可以吃的 
	for(i=0;i<m;i++)
	{
        flag = 0;
    
		if((p+i)->b!=-2) 
		{
		eatnow=(p+i)->b;
		flaglast = 1;
	//	printf("\n%d\n", eatnow) ;
		}
        else
        continue;
            for(j=0;j<m;j++)
	        {
	    	    if((p+j)->a==eatnow&&(p+j)->b!=-2) //左侧列有，且左侧列的右边不是已经吃掉了的，则不可以吃，要跳过 
	        	{
                 flag = 1;
	    	    break;
	    	    }	
	        }
        if (flag==0)//找到可以吃的了 break结束循环 
        {
            break;
        }
	}
	
	if(flaglast==0)
	{
		flaglast = 1;
		for(i=0;i<m;i++)
	{
        flag = 0;
		if((p+i)->a!=-2) 
		{
		eatnow=(p+i)->a;
		}
	}
		
		
	}
	
  //吃掉之后，值为-2，并打印出来 
	for(i=0;i<m;i++)
	{
		if((p+i)->a==eatnow)
		{
		(p+i)->a=-2;
		}
		if((p+i)->b==eatnow)
		{
		(p+i)->b=-2;
		}
	}
	
	if(n==1)
	 printf("%d", eatnow) ;
	 else
     printf("%d,", eatnow) ;
    
	 n--;
	 eatorder(p,m,n);
	 return 0;   
}

int main()
{     
    int n,m;
    int i,j;
    int eatnow;
    scanf("%d %d",&n,&m);
    struct Pre *p= new Pre[m];
    Pre *check = p; 
    Pre *check2 = p; 
    //输入菜品数目和范式数目 
    for(i=0;i<m;i++)
    {
      scanf("%d %d",&(p+i)->a,&(p+i)->b);
    }
    //查询是否可以全部吃完    
    for(i=0;i<m;i++)
    {
        for(j=i+1;j<m;j++)
        {
          	if((check2+j)->b==(check+i)->a&&(check2+j)->a==(check+i)->b)
           	{
           	 printf("None");
           	  return 0;   				
           }
        }
     }
     //打印菜品顺序 
	eatorder(p,m,n);
	 	
		delete p;	 	 
	return 0;   	
}

