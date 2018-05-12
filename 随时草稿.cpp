#include <stdio.h>
#include <iostream>
#include<string.h>
using namespace std;
/*  
如果没有定义任何东西，类的大小为1
这个例子的大小是8
int占据4个字节
虚表格占据四个字节 

*/
class A{
private:
	int i;
public:
	virtual void tunvoid();

};
int main(){
	printf("%d",sizeof(A));
return 0;

}
