#include<stdio.h>  
#include<vector>  
#include <iostream>  
using namespace std;  
int main()  
{  
int i = 0, j = 0;  
//����һ����ά�Ķ�̬���飬��10�У�ÿһ����һ����һ��vector�洢��һ�е����ݡ�  
//����ÿһ�еĳ����ǿ��Ա仯�ġ�
//֮�����õ�vector<int>(0)�Ƕ�vector��ʼ���������ܶ�vector����Ԫ�ء�  
vector< vector<int> > Array( 10, vector<int>(0) );  //�ص㶨�� 

vector<int> Arrayone(10,2);//����һά���� 
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
