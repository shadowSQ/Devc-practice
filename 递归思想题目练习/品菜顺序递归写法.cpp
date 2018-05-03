#include <stdio.h>
#include <iostream>
using namespace std;
/*链接：https://www.nowcoder.com/questionTerminal/9b719f98bb654e74828e3836f74a659a
来源：牛客网

在卡中心隐藏了很多美食，作为一名资深吃货，
楼主告诉你需要去品尝n道美味才能达成“卡中心小小美食家”的成就。
这些菜品被标号为 0 到 n-1 。正所谓美食家不是一口吃成个胖子的，
每道美味的品尝顺序也是有讲究的，
比如西餐的上菜顺序：头盘，汤，副菜，主菜，
蔬菜类菜肴，甜品，咖啡或茶。有一些美味需要“前置菜肴”，
比如如果你要吃菜品0，你需要先吃菜品1，我
们用一个范式来表示这些规则：[0 1]。
接下来给你菜品的总数量n和m个“前置菜肴”的范式，
请编程输出你为了品尝完所有美味所安排的进餐顺序。
可能会有多个正确的顺序，你只要输出一种就可以了。
如果不可能品尝完所有美味，返回None。 
输入描述:

输入的第一行为以空格分隔的两个正整数，
第一个表示原始美味总数n，第二个表示前置菜肴范式总数m。
其后m行每行均为一个以空格分隔的范式说明，
第一列为待吃菜肴的标号，第二列为前置菜肴的标号。


输出描述:

对每组测试数据，单独输出一行答案，菜肴标号之间用英文逗号分隔。*/
int flagover = 0;

//已经被吃了吗 
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

//可以被吃吗 
int CanEat(int (*menu)[2],int *Eated,int m,int cookname,int Eatedcount)
{
	int flag = 1;
	int i,j;
	//1表示可以被吃掉
	//0表示不可以被吃掉
	
	//如果已经被吃掉了，那就不能被吃
	if(isEated(Eated,Eatedcount,cookname))//1表示已经被吃掉了 
		flag = 0;

	
	//如果该菜品在范式左侧，并且其右侧的菜品未被吃,那就不可以吃 
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
//递归执行 
void RepeatEat(int (*menu)[2],int *Eated,int Eatedcount,int n,int m)
{
	
	int i,j;
	int Eatedtemp[n];
	//复制一份已经吃掉的菜单记录 
	for(i=0;i<n;i++)
  	  	{
      		Eatedtemp[i]=Eated[i];
   		}
    
	//只打印一个
	if(flagover ==1)
	return;
    
	//结束条件 
	//菜品吃光了 
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
		//尚未结束时
		//取菜品 
		for(i=0;i<m;i++)
  	  	{
      		for(j=0;j<2;j++)
  	  		{	
				temp = menu[i][j]; 
				//如果可以被吃掉 
			//	printf("temp : %d \n",temp);
      			if(CanEat(menu,Eated,m,temp,Eatedcount))
				{
					
			//		printf("can eat :temp : %d \n",temp);
					//进入“已经被吃掉菜品”数组，记录 
					Eated[Eatedcount] = temp;
					Eatedcount++;
					
					//递归
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
	cin>>n;//菜品数目 = n
	cin>>m;//范式数目 = m； 

	//顺序范式
	int menu[m][2];
	
	//被吃了之后的菜品数量
	int Eated[n]; 
	
	//范式初始化
	for(i=0;i<m;i++)
    {
      scanf("%d %d",&menu[i][0],&menu[i][1]);
    } 
    
    
	 RepeatEat(menu,Eated,0,n,m);
    
	if(flagover == 0)
	printf("None");
	return 0;
	
}
