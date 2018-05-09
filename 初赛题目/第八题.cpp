#include <stdio.h>
// 5  2 将5转化为2进制数    后者范围0~16 
/*一个数可以用二进制表示，
也可以用十进制表示，
如果该数的二进制表示法所有位数字之和等于十进制表示法所有位数字之和，
则称该数为神奇数。比
如：21(十进制)=10101(二进制),所有位数之和为2+1=3,1+0+1+0+1=3。
求小于等于M的神奇数有多少个。*/
#include<math.h>
#include <iostream>
using namespace std;
int counta=0;

int weishujia(int t){
	int i,temp=0;
	
	if(t<10)
	return t;
	else
	{
		while(t>=1)
		{
			temp += t%10;
			t = t/10;
		}
	}
	
	
	return temp;
	
	
}
int zh(unsigned int d,int x)
{
    
 int temp;
 int i=0;
 int a;
    
    //如果是负数
    if(d<0)
    {
        d = -d;
        printf("-");
    }
    
    temp = d;
    
   while(temp>=x)
   {
   	temp /= x;
   	i++;
   }
 int erjinzhishu=0;
 	counta=0;
while(i>=0)
{

	if(d>=pow(x, i))
	{
	a = d /pow(x, i); 
	d = d%(int)pow(x, i);


//	printf("%d",a);
	if(a==1)
	counta++;
//	printf("erjinzhishu:%d",erjinzhishu);
	
	i--;
	}
	else
	{
	erjinzhishu *= 10;
//	printf("0");
	i--;
	}   
}
    return erjinzhishu;
}
int main()
{
	
    int d1,d2;
    int T;
	unsigned int i,conut=0;
	scanf("%d",&T);
	while(T--)
	{
		conut=0;
		unsigned int M;
		
		cin>>M;
    for(i=1;i<=M;i++){
	 
    zh(i,2);//二进制数值
	
	if(counta==weishujia(i))
	{zh(i,2);
//	printf("er  weishu:%d\n",weishujia(zh(i,2)));
//	printf("shi  weishu:%d\n",weishujia(i)); 
//	printf("er  :%d\n",zh(i,2)); 
//	printf("shi  :%d\n",i); 
	conut++;
//	printf("count:  %d\n",conut); 
	
			
	}

    } 
    printf("%d\n",conut);
	}
return 0;
}
