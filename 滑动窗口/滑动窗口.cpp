#include <stdio.h>
#include <iostream>
#include<string.h>
#include <vector>
using namespace std;
/*  滑动窗口  */
/*求出第一次的最大值。在以后的一次操作中。如果最大值的位置还在这个窗口里面。
只要将它和新来的值进行比较，如果不在窗口里面。则重新求出这个窗口里面的最大值。
*/
int nowmax=0;
int maxpos=0;

void Maxnums(vector<int> &nums,int Movenum,int k)
{
	int i;
	nowmax = 0;
	maxpos = 0;
	for(i=Movenum;i<Movenum+k;i++)
	{
		if(nums[i]>nowmax)
		{
			nowmax = nums[i];
			maxpos = i;
		}
	}
}
int main(){

	int T;
	int i;
	vector<int> Answer;
	vector<int> nums;
	int num;
	int n;
	int tempn;
	int k;
	
	cin>>T;//����T 
	while(T--)
	{
		cin>>n;
		tempn=n;
		while(tempn--)
		{
		cin>>num;
		nums.push_back(num);
		}
	
	cin>>k;
	//函数开始
	int Movenum=0;
	
	while((Movenum+k)<=n)
	{
		//
		if(Movenum==0)
		{
			Maxnums(nums,Movenum,k);//得到max和maxpos
		}
		
		if(Movenum!=0&&maxpos>=Movenum&&maxpos<Movenum+k)
		{
			//如果该最大值还在里面，则只要让它和新来的一个数比就可以
			if(nowmax<=nums[Movenum+k-1])
			{
				nowmax = nums[Movenum+k-1];
				maxpos = Movenum+k-1;
			}
		}
		else
		{
			//如果不在，则重新寻找
			Maxnums(nums,Movenum,k);
		}
		
		//一次窗口滤波结束
		
		Answer.push_back(nowmax);
		
		Movenum++;
		
	}
	
	cout<<"Answer:"<<endl;
	for(int j=0;j<Answer.size();j++)
	{
		cout<<Answer[j]<<" ";
	}
	
	
}

return 0;

}
