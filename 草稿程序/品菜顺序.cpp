#include <stdio.h>
//80%ͨ���ʣ���֪��Ϊɶ������Ҫ�������˵�Ŷ �� 
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
	
  //�ҵ�һ�����ԳԵ��Ǹ���Ʒ��˼·Ϊ�Ҳ����У����������û�е���һ���ˣ�һ���ǿ��ԳԵ� 
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
	    	    if((p+j)->a==eatnow&&(p+j)->b!=-2) //������У�������е��ұ߲����Ѿ��Ե��˵ģ��򲻿��Գԣ�Ҫ���� 
	        	{
                 flag = 1;
	    	    break;
	    	    }	
	        }
        if (flag==0)//�ҵ����ԳԵ��� break����ѭ�� 
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
	
  //�Ե�֮��ֵΪ-2������ӡ���� 
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
    //�����Ʒ��Ŀ�ͷ�ʽ��Ŀ 
    for(i=0;i<m;i++)
    {
      scanf("%d %d",&(p+i)->a,&(p+i)->b);
    }
    //��ѯ�Ƿ����ȫ������    
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
     //��ӡ��Ʒ˳�� 
	eatorder(p,m,n);
	 	
		delete p;	 	 
	return 0;   	
}

