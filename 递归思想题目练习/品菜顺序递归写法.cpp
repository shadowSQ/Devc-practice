#include <stdio.h>
#include <iostream>
using namespace std;
/*���ӣ�https://www.nowcoder.com/questionTerminal/9b719f98bb654e74828e3836f74a659a
��Դ��ţ����

�ڿ����������˺ܶ���ʳ����Ϊһ������Ի���
¥����������ҪȥƷ��n����ζ���ܴ�ɡ�������СС��ʳ�ҡ��ĳɾ͡�
��Щ��Ʒ�����Ϊ 0 �� n-1 ������ν��ʳ�Ҳ���һ�ڳԳɸ����ӵģ�
ÿ����ζ��Ʒ��˳��Ҳ���н����ģ�
�������͵��ϲ�˳��ͷ�̣��������ˣ����ˣ�
�߲�����ȣ���Ʒ�����Ȼ�衣��һЩ��ζ��Ҫ��ǰ�ò��ȡ���
���������Ҫ�Բ�Ʒ0������Ҫ�ȳԲ�Ʒ1����
����һ����ʽ����ʾ��Щ����[0 1]��
�����������Ʒ��������n��m����ǰ�ò��ȡ��ķ�ʽ��
���������Ϊ��Ʒ����������ζ�����ŵĽ���˳��
���ܻ��ж����ȷ��˳����ֻҪ���һ�־Ϳ����ˡ�
���������Ʒ����������ζ������None�� 
��������:

����ĵ�һ��Ϊ�Կո�ָ���������������
��һ����ʾԭʼ��ζ����n���ڶ�����ʾǰ�ò��ȷ�ʽ����m��
���m��ÿ�о�Ϊһ���Կո�ָ��ķ�ʽ˵����
��һ��Ϊ���Բ��ȵı�ţ��ڶ���Ϊǰ�ò��ȵı�š�


�������:

��ÿ��������ݣ��������һ�д𰸣����ȱ��֮����Ӣ�Ķ��ŷָ���*/
int flagover = 0;

//�Ѿ��������� 
int isEated(int *Eated,int Eatedcount,int cookname)
{		
		int i;
		for(i=0;i<Eatedcount;i++)
  	  	{
  	  		if(Eated[i]==cookname)
  	  		return 1;
   		}
   		return 0;
}

//���Ա����� 
int CanEat(int (*menu)[2],int *Eated,int m,int cookname,int Eatedcount)
{
	int flag = 1;
	int i,j;
	//1��ʾ���Ա��Ե�
	//0��ʾ�����Ա��Ե�
	
	//����Ѿ����Ե��ˣ��ǾͲ��ܱ���
	if(isEated(Eated,Eatedcount,cookname))//1��ʾ�Ѿ����Ե��� 
		flag = 0;

	
	//����ò�Ʒ�ڷ�ʽ��࣬�������Ҳ�Ĳ�Ʒδ����,�ǾͲ����Գ� 
	for(i=0;i<m;i++)
	{
		if(menu[i][0]==cookname)
		{
			if(isEated(Eated,Eatedcount,menu[i][1])!=1)
			flag = 0;
		}
	}
	return flag;
	
}
//�ݹ�ִ�� 
void RepeatEat(int (*menu)[2],int *Eated,int Eatedcount,int n,int m)
{
	
	int i,j;
	int Eatedtemp[n];
	//����һ���Ѿ��Ե��Ĳ˵���¼ 
	for(i=0;i<n;i++)
  	  	{
      		Eatedtemp[i]=Eated[i];
   		}
    
	//ֻ��ӡһ��
	if(flagover ==1)
	return;
    
	//�������� 
	//��Ʒ�Թ��� 
	if(Eatedcount==n)
	{
		for(i=0;i<n-1;i++)
  	  	{
      		printf("%d,",Eated[i]);
   		}
   		printf("%d",Eated[n-1]);

		flagover = 1;
	}
	else
	{
		int temp; 
		//��δ����ʱ
		//ȡ��Ʒ 
		for(i=0;i<m;i++)
  	  	{
      		for(j=0;j<2;j++)
  	  		{	
				temp = menu[i][j]; 
				//������Ա��Ե� 
			//	printf("temp : %d \n",temp);
      			if(CanEat(menu,Eated,m,temp,Eatedcount))
				{
					
			//		printf("can eat :temp : %d \n",temp);
					//���롰�Ѿ����Ե���Ʒ�����飬��¼ 
					Eated[Eatedcount] = temp;
					Eatedcount++;
					
					//�ݹ�
					RepeatEat(menu,Eated,Eatedcount,n,m);
					
					Eatedcount--;
					
				}
			} 
   		}
		
	}
}
int main(){
	int n,m,i,j;
	int Eatedcount = 0; 
	cin>>n;//��Ʒ��Ŀ = n
	cin>>m;//��ʽ��Ŀ = m�� 

	//˳��ʽ
	int menu[m][2];
	
	//������֮��Ĳ�Ʒ����
	int Eated[n]; 
	
	//��ʽ��ʼ��
	for(i=0;i<m;i++)
    {
      scanf("%d %d",&menu[i][0],&menu[i][1]);
    } 
    
    
	 RepeatEat(menu,Eated,0,n,m);
    
	if(flagover == 0)
	printf("None");
	return 0;
	
}
