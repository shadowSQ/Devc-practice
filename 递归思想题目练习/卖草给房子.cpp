#include <stdio.h>
//有一排房子，卖东西给他们
//相邻的房子不能一起卖
//问：最多可以卖多少钱
//注意，第一个和最后一个算是相邻的房子 
int count = 0;
int price[5]={1,2,3,4,2};
int maxprice=0;
int isEND(int n,int *house){
	int i;
	int flag = 1;//如果结束了，flag置为1
				//未结束，flag = = 0；
	for(i=0;i<n;i++)
	{
		if(i==0&&house[i]==0)//特殊：第一个房子
		{
			if(house[n-1]!=1&&house[1]!=1)
				flag = 0;
		}
		if(i==n-1&&house[i]==0)//特殊：最后一个房子
		{
			if(house[n-2]!=1&&house[0]!=1)
				flag = 0;
		}
		if(i!=0&&i!=n-1&&house[i]==0)//任意位置
		{
			if(house[i-1]!=1&&house[i+1]!=1)
				flag = 0;
		}
	}
	return flag;
}
int SellAble(int n,int i,int *house)
{
	int flag = 1;//1表示可以卖，0表示不可以
	
	
	if(i==0)
	{
		if(house[1]==1||house[n-1]==1)
			flag = 0;
	}
	if(i==n-1)
	{	
		if(house[0]==1||house[n-2]==1)
			flag = 0;
	}
	if(i!=0&&i!=(n-1))
	{
		if(house[i-1]==1||house[i+1]==1)
		flag = 0;
	}
		
	return flag;
}
void RepeatSell(int n,int *house)
{
	int house2[n],i,j;
	//复制当前贩卖情况
	int tempmaxprice = 0;//用于价格比较 
	for(i=0;i<n;i++)
	house2[i] = house[i];
	
//	printf("house2:\n");
//	for(i=0;i<n;i++)
//	printf("%d ",house2[i]);
	//printf("\n");
	
	if(isEND(n,house2))
	{
		count++;
		printf("第%d种Answer:\n",count);
		for(i=0;i<n;i++)
		printf("%d ",house2[i]);
		printf("\n");	
		for(i=0;i<n;i++)
		{
			if(house2[i]==1)
			{
				tempmaxprice += price[i];
				
			} 
		} 
		printf("这种情况的金额：%d \n",tempmaxprice);
			printf("\n");
			
	}
	else 
	{//未结束，判断哪一个房子可以卖
		for(i=0;i<n;i++)
		{
			if(house2[i]==0)
			{
				if(SellAble(n,i,house2))
				{
				//如果可以贩卖
				house2[i] = 1;
			//	printf("house2 after:\n");
			//	for(j=0;j<n;j++)
			//	printf("%d ",house2[j]);
			//printf("\n");
				RepeatSell(n,house2);
				
				house2[i] = 0;
				}
			}
			
		}
	
	}
	
	
	
}
int main(){
	int n,i;
	
	scanf("%d",&n);
	int House[n]; 
	//初始化
	for(i=0;i<n;i++)
	House[i] = 0 ;
	//没有卖的为0，卖了的为1
	
	
	RepeatSell(n,House); 
	
	return 0;
}

