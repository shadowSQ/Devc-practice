#include<stdio.h>  
#include<vector>  
#include <iostream>  
using namespace std;  
int main()  
{  
int i = 0, j = 0;  
//定义一个二维的动态数组，有10行，每一行是一个用一个vector存储这一行的数据。  
//所以每一行的长度是可以变化的。
//之所以用到vector<int>(0)是对vector初始化，否则不能对vector存入元素。  
vector< vector<int> > Array( 10, vector<int>(0) );  //重点定义 

vector<int> Arrayone(10,2);//定义一维数组 
for( j = 0; j < 10; j++ )  
{  
cout<<Arrayone[j];
}
for( j = 0; j < 10; j++ )  
{  
 for ( i = 0; i < 5; i++ )  
 {  
  Array[ j ].push_back( i );  
 }  
}  
for( j = 0; j < 10; j++ )  
{  
 for( i = 0; i < Array[ j ].size(); i++ )  
 {  
  cout << Array[ j ][ i ] << " ";  
 }  
 cout<< endl;  
}  
}   
