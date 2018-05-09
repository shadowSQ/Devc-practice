#include <stdio.h>
#include <iostream>
using namespace std;
/*  
Input:
2
5
1 9 2 3 8
9 8 3 2 1

Output:
14
0   */
int MONEY=0; 
int maxweal(int *city,int N)
{
	MONEY = 0;
	
	int flagcost = 0;//0为待买状态，1为待卖状态
	int i=0,j=0;
	int Nowbuy = 0;
	int Nowsell = 0; 

	while(j<N) 
	{	
		int tempj=j;
		if(j==N-1)
		{
			break;
		}
		
	
		if(flagcost==0) 
		{
		for(i=tempj;i<N;i++)
		{
						
			if(city[i+1]<city[i])//如果下一个比它少钱，不动作 
			{
			j = i; 
			continue;	
			}
			if(city[i+1]>=city[i])//如果下一个比它多钱，动作，因为可以盈利 
			{
			Nowbuy = city[i];//买了它	
			MONEY -= Nowbuy;
			flagcost =1;//状态转变为待卖状态 
//			printf("\nafterbuy:MONEY:%d \n",MONEY);
			j = i; 
			j++; 
			break;
			}
		}
		}
		
		tempj=j;
		
//		printf("\nJJJJ	:%d \n",tempj);
		if(flagcost==1) 
		{//待卖状态
			 for(i=tempj;i<N;i++)
			{
				if(city[i+1]>=city[i])//如果下一个可以卖的钱比他多的话去下一个，不动作 
				{
				j = i; 
				continue;	
				}
				if(city[i+1]<city[i])//如果下一个可以卖的钱比他少，卖了 
				{
				Nowsell = city[i];
				j = i; 
				flagcost = 0;
				MONEY += Nowsell;
//				printf("\naftersell:MONEY:%d \n",MONEY);
				j++; 
				break;		
				}
				
			
			}
		
		}
	}
	

} 
int main(){


	int T;
	int i;
	int N; 
	scanf("%d",&T);

	scanf("%d",&N);
	int city[N+1];
	while(T--)
	{
	 
	for(i=0;i<N;i++)
	{
	scanf("%d",&city[i]);
	}
//	for(i=0;i<N;i++)
//	{
//		printf("%d ",city[i]);
//	}
	city[N] = 0;
	maxweal(city,N);
	printf("%d \n",MONEY);
	}

return 0;

}

