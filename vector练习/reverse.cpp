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
*///���Ҫ�Ӵ�С������д
//���õ�ʱ����sort(vec.begin(),vec.end(),Comp); 

int main(){
	
	vector<int> vec;
	vec.push_back(1);
	cout<<vec[0]<<endl;//����1��ʾ����Ļ��
	
	vec.push_back(2);
	
	vector<int>::iterator i;
	for(i=vec.begin();i!=vec.end();i++)
		cout<<*i<<" "; 
		
	cout<<endl;
	
	
	vec.insert(vec.begin()+1,3);//�ڵ�i��λ�ò���һ�����ݽṹ 
	cout<<"���ض�λ�ò��루3��������1���棺"<<endl;
	for(i=vec.begin();i!=vec.end();i++)
		cout<<*i<<" ";
		
	cout<<endl;
	cout<<"���ض�λ��ɾ����3����"<<endl;
	vec.erase(vec.begin()+1 );//ɾ����i��λ�õ����ݽṹ 
	
	for(i=vec.begin();i!=vec.end();i++)
		cout<<*i<<" ";
		
		cout<<endl;
	
	vec.clear();//�������vector 
	
	for(int j= 0;j<10;j++)
		vec.push_back(j);
	
	for(i=vec.begin();i!=vec.end();i++)
		cout<<*i<<" ";
	cout<<endl;
	
	cout<<"ɾ��3��4�������ֺ�"<<endl;
	vec.erase(vec.begin()+3,vec.end()-5);//ɾ����3��ʼ��5-1�������������� ��3,4�� 
	
	for(i=vec.begin();i!=vec.end();i++)
		cout<<*i<<" ";
	cout<<endl;
	
	//���²������� 
	vec.insert(vec.begin()+3,3);
	vec.insert(vec.begin()+4,4);
	
	cout<<"��ԭ���������һ����Ԫ�أ�"<<endl;
	reverse(vec.begin()+2,vec.end()-3);//������  (��2��ʼ��10-3-1����)
	
	for(i=vec.begin();i!=vec.end();i++)
		cout<<*i<<" ";
	cout<<endl;
	
	sort(vec.begin(),vec.end());//����Ĭ�ϴ�С���󣬣�ע��ղŽ�0~9�����ˣ� 
	
	cout<<"���������"<<endl;
	for(i=vec.begin();i!=vec.end();i++)
		cout<<*i<<" ";
	cout<<endl;
	
	//���Ԫ�صķ���
	int ic;
	int N = vec.size();
	//��һ�� 
	for(ic=0;ic<N;ic++)
	cout<<vec[ic]<<" ";
	cout<<endl;
	//�ڶ���
	for(ic=0;ic<N;ic++)
	cout<<vec.at(ic)<<" "; 
	cout<<endl;
	
	return 0;
}
