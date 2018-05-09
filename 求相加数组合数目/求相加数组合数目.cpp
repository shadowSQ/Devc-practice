#include <stdio.h>
/*

问题描述：
输入n个不相同的数字，再输入一个数字Y。 
要用那n个若干个数字组合相加 等于Y，问有多少种组合方法。
例如输入3个数字 1 2 5 ，再输入一个数字Y=5，则共有
1+1+1+1+1,1+1+1+2，1+2+2，5，一共有四种

解题思路，利用递归，每回执行的操作为：
1.取n个数字中最大的那个， 
2.Y除以max (n),得到除数
3.
	对于组合中有几个max(n),对应情况讨论 
	比如 11 除以 5 除数为2 
	根据： 
	
	3.1：11 由2个5组合时， 对11-2*5 = 1 
	执行操作 (取n数字组合中去掉最后的组合为 (2,1)) 
	重复操作
	
	3.2：11 由1个5组合时， 对11-1*5 = 6 
 	对6执行操作，在(2,1)中取最大的数字，
 	然后除以它，然后对有几个2的情况，重复讨论 
 
 	例如：对6操作，6/2 = 3 ;
 	在6组合中有0个，1个 2时，对应 6 -1*2  =4 
 	对4取 max(1)，显然只有一种组合就是1+1+1+1了 
 
	3.3： 11 由0个5组合时， 对11-0*5 = 11 
 	对11执行操作，在(2,1)中取最大的数字，
 	然后除以它，然后对有几个2时，重复讨论 
 	
4.因为组合中有 2个5,1个5,0个5，这三种情况是唯一的
 因此不会出现重复 ，把他们组合数相加就是最终数量 
 
*/
/*
该程序一个输入和输出用例： 
3
15
2 3 6
now count: 0
+3+2+2+2+2+2+2  now count: 1
+3+3now count: 1		//15-6=9  2凑不出9所以count不变 
+3+3+3+2+2+2  now count: 2
+3+3+3+3now count: 2	//15-12=3  2凑不出3所以count不变 
+3+3+3+3+3  now count: 3
now count: 3
+6now count: 3			//15-6=9  2凑不出9所以count不变 
+3+2+2+2  now count: 4
+3+3now count: 4
+3+3+3  now count: 5
now count: 5
+6+6now count: 5
+3  now count: 6
now count: 6
6
最终结果：6种 
*/
//Y:目标数字 
//numbers:数字数组 
//n:数组长度 
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
	//求出，去掉了最大数之后的数组 newnumbers
	for(i=0;i<n;i++)
		if(numbers[i]<maxofnumbers)
		newnumbers[countnew++] = numbers[i];
//	printf(" max:%d ",maxofnumbers);	
//	for(i=0;i<n;i++)
//	printf("%d ",newnumbers[i]);
	//直接结束条件 
	if(n==1) 
	{
		//如果余数为0 
		//如果最小的那个数字组合不可以组成该Y，则就是组合数目就是0 
		if((Y%(maxofnumbers))!=0)
		return;
		else
		{
			x = Y/maxofnumbers;
			while(x--)
			printf("+%d",maxofnumbers);
			printf("  ");
			Ncount++;
			return;//否则是1 
		}
	}
	else
	{
		//未结束时
		int t;
		int YuShu;
		t = Y/(maxofnumbers);//例如 11/5 时候 t==2
		
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
	//首先需要输入一共有几个数字
	int n;
	scanf("%d",&n);
	//然后是Y
	int Y;
	scanf("%d",&Y);
	//声明一个数组存放n个数字 
    int numbers[n];
	  
	  //输入n个对应数字
	int i;
	for(i=0;i<n;i++)
	scanf("%d",&numbers[i]);
	
//	for(i=0;i<n;i++)
//	printf("%d",numbers[i]);
	RepeatCre(Y,numbers,n);
	printf("最终结果：%d",Ncount);
	
	return 0;
} 
