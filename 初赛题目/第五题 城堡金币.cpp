#include <stdio.h>
#include <iostream>
#include<string.h>
using namespace std;
/*   // ��¼�Ǳ���·�Ͻ����Ϣ�Ľṹ��
// �ӳǱ�castle_from���Ǳ�castle_to��·����coins�����
struct road{
 int castle_from; 
 int castle_to;   
 int coins;
};

// ��������ܻ�ȡ���Ľ�Ҹ���
// ������roads         ·���ͽ����Ϣ����
// ������roads_count   roads����
// ������castles_count �Ǳ�����
// ����ֵ����ȡ���Ľ�Ҹ���
int max_coin(const road roads[], int roads_count, int castles_count);


Input:
1
7 //7���Ǳ� 
9	//����· 
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
	//ģ������߹���·�� /1�����߹���0 ����δ�߹� 
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
	{//�Ѿ�����ʱ
		 if(maxcoincount<nowcoins)
		 {
		 	maxcoincount = nowcoins;
		 	printf("overcoins:%d\n",maxcoincount);
		 }
	} 
	else
	{
		//δ����ʱ�� 
		for(i=0;i<roads;i++)
		{
			if(roadcoins[i][0]==nowpoint)//����Ǳ���·�����ߵ���һ���Ǳ� qian hou
			{
				if(templuguo[roadcoins[i][1]]!=1;)//��������ط���û�߹� 
				{
					quguoflag = 1;
					templuguo[roadcoins[i][1]]=1;// ����һ�� 
					//����ͼ������ʶ�����ң���λ�� ,����һ�� 
					seekcoins(roadcoins,citys,roads,templuguo,nowcoins+roadcoins[i][3],roadcoins[i][1],roadcoins[i][0]); 
				}
			}
			if(roadcoins[i][1]==nowpoint)//����Ǳ���·���Ե�  hou qian
			{
				if(luguo[roadcoins[i][0]]!=1;)//��������ط���û�߹� 
				{
					quguoflag = 1;
					
					templuguo[roadcoins[i][0]]=1;
					
					seekcoins(roadcoins,citys,roads,templuguo,nowcoins+roadcoins[i][3],roadcoins[i][0],roadcoins[i][1]); 
					
				}
			}
			
		}
		//�������֮�󣬷���û��һ���ط���ûȥ���ģ���ʱ��û����
		//��Ҫ������ 
		if(quguoflag == 0)
		{
			
			//����Ѿ��߹���
			//�ж�������·�� 
			if(lastpoint==roadcoins[i][1])
					{
						//���������·	//�ж��Ƿ���˻�ȥ��·���� 
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
		
		for(i=0;i<roads;i++)//·���б��ʼ�� 1�����߹��� 
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
