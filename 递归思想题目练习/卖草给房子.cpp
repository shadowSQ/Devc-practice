#include <stdio.h>
//��һ�ŷ��ӣ�������������
//���ڵķ��Ӳ���һ����
//�ʣ�������������Ǯ
//ע�⣬��һ�������һ���������ڵķ��� 
int count = 0;
int price[5]={1,2,3,4,2};
int maxprice=0;
int isEND(int n,int *house){
	int i;
	int flag = 1;//��������ˣ�flag��Ϊ1
				//δ������flag = = 0��
	for(i=0;i<n;i++)
	{
		if(i==0&&house[i]==0)//���⣺��һ������
		{
			if(house[n-1]!=1&&house[1]!=1)
				flag = 0;
		}
		if(i==n-1&&house[i]==0)//���⣺���һ������
		{
			if(house[n-2]!=1&&house[0]!=1)
				flag = 0;
		}
		if(i!=0&&i!=n-1&&house[i]==0)//����λ��
		{
			if(house[i-1]!=1&&house[i+1]!=1)
				flag = 0;
		}
	}
	return flag;
}
int SellAble(int n,int i,int *house)
{
	int flag = 1;//1��ʾ��������0��ʾ������
	
	
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
	//���Ƶ�ǰ�������
	int tempmaxprice = 0;//���ڼ۸�Ƚ� 
	for(i=0;i<n;i++)
	house2[i] = house[i];
	
//	printf("house2:\n");
//	for(i=0;i<n;i++)
//	printf("%d ",house2[i]);
	//printf("\n");
	
	if(isEND(n,house2))
	{
		count++;
		printf("��%d��Answer:\n",count);
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
		printf("��������Ľ�%d \n",tempmaxprice);
			printf("\n");
			
	}
	else 
	{//δ�������ж���һ�����ӿ�����
		for(i=0;i<n;i++)
		{
			if(house2[i]==0)
			{
				if(SellAble(n,i,house2))
				{
				//������Է���
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
	//��ʼ��
	for(i=0;i<n;i++)
	House[i] = 0 ;
	//û������Ϊ0�����˵�Ϊ1
	
	
	RepeatSell(n,House); 
	
	return 0;
}

