#include <stdio.h>
/*

����������
����n������ͬ�����֣�������һ������Y�� 
Ҫ����n�����ɸ����������� ����Y�����ж�������Ϸ�����
��������3������ 1 2 5 ��������һ������Y=5������
1+1+1+1+1,1+1+1+2��1+2+2��5��һ��������

����˼·�����õݹ飬ÿ��ִ�еĲ���Ϊ��
1.ȡn�������������Ǹ��� 
2.Y����max (n),�õ�����
3.
	����������м���max(n),��Ӧ������� 
	���� 11 ���� 5 ����Ϊ2 
	���ݣ� 
	
	3.1��11 ��2��5���ʱ�� ��11-2*5 = 1 
	ִ�в��� (ȡn���������ȥ���������Ϊ (2,1)) 
	�ظ�����
	
	3.2��11 ��1��5���ʱ�� ��11-1*5 = 6 
 	��6ִ�в�������(2,1)��ȡ�������֣�
 	Ȼ���������Ȼ����м���2��������ظ����� 
 
 	���磺��6������6/2 = 3 ;
 	��6�������0����1�� 2ʱ����Ӧ 6 -1*2  =4 
 	��4ȡ max(1)����Ȼֻ��һ����Ͼ���1+1+1+1�� 
 
	3.3�� 11 ��0��5���ʱ�� ��11-0*5 = 11 
 	��11ִ�в�������(2,1)��ȡ�������֣�
 	Ȼ���������Ȼ����м���2ʱ���ظ����� 
 	
4.��Ϊ������� 2��5,1��5,0��5�������������Ψһ��
 ��˲�������ظ� ���������������Ӿ����������� 
 
*/
/*
�ó���һ���������������� 
3
15
2 3 6
now count: 0
+3+2+2+2+2+2+2  now count: 1
+3+3now count: 1		//15-6=9  2�ղ���9����count���� 
+3+3+3+2+2+2  now count: 2
+3+3+3+3now count: 2	//15-12=3  2�ղ���3����count���� 
+3+3+3+3+3  now count: 3
now count: 3
+6now count: 3			//15-6=9  2�ղ���9����count���� 
+3+2+2+2  now count: 4
+3+3now count: 4
+3+3+3  now count: 5
now count: 5
+6+6now count: 5
+3  now count: 6
now count: 6
6
���ս����6�� 
*/
//Y:Ŀ������ 
//numbers:�������� 
//n:���鳤�� 
int Ncount = 0;
int max(int *numbers,int n)
{
	int maxn=0,i;
	for(i=0;i<n;i++)
	if(maxn<=numbers[i])
	maxn = numbers[i];
	return maxn;
	
}
void RepeatCre(int Y,int *numbers,int n){
	
	int i;
	int newnumbers[n];
	int maxofnumbers = max(numbers,n);
	int countnew = 0 ;
	int x;
	//�����ȥ���������֮������� newnumbers
	for(i=0;i<n;i++)
		if(numbers[i]<maxofnumbers)
		newnumbers[countnew++] = numbers[i];
//	printf(" max:%d ",maxofnumbers);	
//	for(i=0;i<n;i++)
//	printf("%d ",newnumbers[i]);
	//ֱ�ӽ������� 
	if(n==1) 
	{
		//�������Ϊ0 
		//�����С���Ǹ�������ϲ�������ɸ�Y������������Ŀ����0 
		if((Y%(maxofnumbers))!=0)
		return;
		else
		{
			x = Y/maxofnumbers;
			while(x--)
			printf("+%d",maxofnumbers);
			printf("  ");
			Ncount++;
			return;//������1 
		}
	}
	else
	{
		//δ����ʱ
		int t;
		int YuShu;
		t = Y/(maxofnumbers);//���� 11/5 ʱ�� t==2
		
			for(i=0;i<=t;i++) 
			{
				int j=i;
				YuShu = Y - i * (maxofnumbers);
			//	printf("Yushu: %d \n",YuShu);
			
				while(j--)
				printf("+%d",(maxofnumbers));
				
				RepeatCre(YuShu,newnumbers,n-1);
				
				printf("now count: %d \n",Ncount);
			}
		
	} 
	
}
int main(){
	//������Ҫ����һ���м�������
	int n;
	scanf("%d",&n);
	//Ȼ����Y
	int Y;
	scanf("%d",&Y);
	//����һ��������n������ 
    int numbers[n];
	  
	  //����n����Ӧ����
	int i;
	for(i=0;i<n;i++)
	scanf("%d",&numbers[i]);
	
//	for(i=0;i<n;i++)
//	printf("%d",numbers[i]);
	RepeatCre(Y,numbers,n);
	printf("���ս����%d",Ncount);
	
	return 0;
} 
