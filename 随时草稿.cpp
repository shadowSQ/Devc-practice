#include <stdio.h>
#include <iostream>
#include<string.h>
using namespace std;
/*  
���û�ж����κζ�������Ĵ�СΪ1
������ӵĴ�С��8
intռ��4���ֽ�
����ռ���ĸ��ֽ� 

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
