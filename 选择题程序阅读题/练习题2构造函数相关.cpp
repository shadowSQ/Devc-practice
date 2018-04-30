#include<iostream>
using namespace std;
class MyClass
{
public:
    MyClass(int i = 0)
    {
        cout << i;
    }
    MyClass(const MyClass &x)
    {
        cout << 2;
    }
    MyClass &operator=(const MyClass &x)
    {
        cout << 3;
        return *this;
    }

    ~MyClass()
    {
        cout << 4;
    }
};
int main()
{
    MyClass obj1(1);   //��һ�ֹ��캯��   1
    
    MyClass obj2(obj1);//�ڶ��ֹ��캯��   2
    
    MyClass obj3;      //��һ�ֹ��캯��   0
    
    obj3 = obj1;       //�����ֹ��캯�� �������ص�Ŀ�������ʹ�ö���Ϊ����ʱ����   3
     
    MyClass obj4=obj1; //�൱�ڵڶ��ֹ��캯��   2

    return 0;          //�����������ֽ�4��Myclass�� 
}
