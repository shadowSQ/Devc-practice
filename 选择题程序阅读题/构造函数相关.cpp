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
    MyClass obj1(1);   //第一种构造函数   1
    
    MyClass obj2(obj1);//第二种构造函数   2
    
    MyClass obj3;      //第一种构造函数   0
    
    obj3 = obj1;       //第三种构造函数 ，当重载单目运算符的使用对象为本类时调用   3
     
    MyClass obj4=obj1; //相当于第二种构造函数   2

    return 0;          //析构函数，分解4个Myclass类 
}
