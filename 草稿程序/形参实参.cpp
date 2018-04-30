#include <stdio.h> 
#include <iostream> 
using namespace std;
void swap(int &a,int &b)
{
     int temp;
     temp=a;
     a=b;
     b=temp;
     cout<<a<<b<<endl;
}
void swap2(int a,int b)
{
     int temp;
     temp=a;
     a=b;
     b=temp;
     cout<<a<<b<<endl;
}
 
int main(){
     
    int x=1;
    int y=2;
    swap2(x,y);
     cout<<x<<' '<<y<<endl;
    swap(x,y);

    cout<<x<<' '<<y<<endl;
    return 0;
}
