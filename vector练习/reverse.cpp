#include<stdio.h>  
#include<algorithm>  
#include<vector>  
#include<iostream>  
using namespace std;

/*
bool Comp(const int &a,const int &b)
{
    return a>b;
}
bool comp(const int &a,const int &b)
{return a>b;}
*///如果要从大到小就这样写
//调用的时候是sort(vec.begin(),vec.end(),Comp); 

int main(){
	
	vector<int> vec;
	vec.push_back(1);
	cout<<vec[0]<<endl;//数字1显示在屏幕上
	
	vec.push_back(2);
	
	vector<int>::iterator i;
	for(i=vec.begin();i!=vec.end();i++)
		cout<<*i<<" "; 
		
	cout<<endl;
	
	
	vec.insert(vec.begin()+1,3);//在第i个位置插入一个数据结构 
	cout<<"在特定位置插入（3）插入在1后面："<<endl;
	for(i=vec.begin();i!=vec.end();i++)
		cout<<*i<<" ";
		
	cout<<endl;
	cout<<"在特定位置删除（3）："<<endl;
	vec.erase(vec.begin()+1 );//删除第i个位置的数据结构 
	
	for(i=vec.begin();i!=vec.end();i++)
		cout<<*i<<" ";
		
		cout<<endl;
	
	vec.clear();//清空容器vector 
	
	for(int j= 0;j<10;j++)
		vec.push_back(j);
	
	for(i=vec.begin();i!=vec.end();i++)
		cout<<*i<<" ";
	cout<<endl;
	
	cout<<"删除3和4两个数字后："<<endl;
	vec.erase(vec.begin()+3,vec.end()-5);//删除从3开始到5-1结束了两个数字 （3,4） 
	
	for(i=vec.begin();i!=vec.end();i++)
		cout<<*i<<" ";
	cout<<endl;
	
	//重新补充完整 
	vec.insert(vec.begin()+3,3);
	vec.insert(vec.begin()+4,4);
	
	cout<<"复原数组后，逆序一部分元素："<<endl;
	reverse(vec.begin()+2,vec.end()-3);//逆序函数  (从2开始，10-3-1结束)
	
	for(i=vec.begin();i!=vec.end();i++)
		cout<<*i<<" ";
	cout<<endl;
	
	sort(vec.begin(),vec.end());//排序，默认从小到大，（注意刚才将0~9逆序了） 
	
	cout<<"重新排序后："<<endl;
	for(i=vec.begin();i!=vec.end();i++)
		cout<<*i<<" ";
	cout<<endl;
	
	//输出元素的方法
	int ic;
	int N = vec.size();
	//第一种 
	for(ic=0;ic<N;ic++)
	cout<<vec[ic]<<" ";
	cout<<endl;
	//第二种
	for(ic=0;ic<N;ic++)
	cout<<vec.at(ic)<<" "; 
	cout<<endl;
	
	return 0;
}
