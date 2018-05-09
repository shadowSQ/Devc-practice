#include <stdio.h>
#include <iostream>
#include<string.h>
using namespace std;
/*   // 记录城堡间路上金币信息的结构体
// 从城堡castle_from到城堡castle_to的路上有coins个金币
struct road{
 int castle_from; 
 int castle_to;   
 int coins;
};

// 计算最多能获取到的金币个数
// 参数：roads         路径和金币信息数组
// 参数：roads_count   roads数量
// 参数：castles_count 城堡个数
// 返回值：获取到的金币个数
int max_coin(const road roads[], int roads_count, int castles_count);


Input:
1
7 //7个城堡 
9	//九条路 
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
1 4 3
3 5 3
4 6 9
5 6 7

Output:
50  */
int maxcoincount = 0; 
int seekcoins(int roadcoins[][3],int citys,int roads,int *luguo,int nowcoins,int nowpoint,int lastpoint)
{
	int i100; 
	int citys2 = citys;
	int roads2 = roads;
	int i;
	int startpoint = 0; 
	int quguoflag = 0;
	int templuguo[citys2]; 
	//模板放置走过的路径 /1代表走过，0 代表未走过 
	 	for(i=0;i<citys;i++)
	{
		templuguo[i] = luguo[i];
	}
	for(i=0;i<citys;i++)
	{
		printf("%d ",templuguo[i]);
	}
		 
		for(i=0;i<roads;i++)
	{
		printf("%d ",roadcoins[i][0]);
		printf("%d ",roadcoins[i][1]);
		printf("%d ",roadcoins[i][2]);
		printf("\n");
	}
	
	if(ENDcity)
	{//已经结束时
		 if(maxcoincount<nowcoins)
		 {
		 	maxcoincount = nowcoins;
		 	printf("overcoins:%d\n",maxcoincount);
		 }
	} 
	else
	{
		//未结束时候 
		for(i=0;i<roads;i++)
		{
			if(roadcoins[i][0]==nowpoint)//这个城堡有路可以走到另一个城堡 qian hou
			{
				if(templuguo[roadcoins[i][1]]!=1;)//并且这个地方还没走过 
				{
					quguoflag = 1;
					templuguo[roadcoins[i][1]]=1;// 到此一游 
					//带地图，带常识，捡金币，换位置 ,到此一游 
					seekcoins(roadcoins,citys,roads,templuguo,nowcoins+roadcoins[i][3],roadcoins[i][1],roadcoins[i][0]); 
				}
			}
			if(roadcoins[i][1]==nowpoint)//这个城堡有路可以到  hou qian
			{
				if(luguo[roadcoins[i][0]]!=1;)//并且这个地方还没走过 
				{
					quguoflag = 1;
					
					templuguo[roadcoins[i][0]]=1;
					
					seekcoins(roadcoins,citys,roads,templuguo,nowcoins+roadcoins[i][3],roadcoins[i][0],roadcoins[i][1]); 
					
				}
			}
			
		}
		//遍历完成之后，发现没有一个地方是没去过的，这时候还没结束
		//就要讨论了 
		if(quguoflag == 0)
		{
			
			//如果已经走过了
			//判断是来的路吗 
			if(lastpoint==roadcoins[i][1])
					{
						//如果是来的路	//判断是否除了回去无路可走 
						for(i100=0;i100<roads;i100++)
						{
							if(roadcoins[i100][0]==nowpoint)
							{
								if(roadcoins[i100][1]==lastpoint)
								
							} 
						}
						 
						 
					}
			
			
		} 
		
							
					 
				} 
			}
	}

}

int main(){

	int T,N;
	int i;
	scanf("%d",&T);

	
	while(T--)
	{
		int citys;
		scanf("%d",&citys);
		printf("countcitys:%d ",citys);
		int roads;
		scanf("%d",&roads);
		printf("countloads:%d ",roads);
		
		int roadcoins[roads][3];
		
		int luguo[roads];
		
		for(i=0;i<roads;i++)//路过列表初始化 1代表走过了 
			luguo[i]=0;

	for(i=0;i<roads;i++)
	{
		scanf("%d",&roadcoins[i][0]);
		scanf("%d",&roadcoins[i][1]);
		scanf("%d",&roadcoins[i][2]);
	}

	
	seekcoins(roadcoins,citys,roads,luguo);
	}

return 0;

}
