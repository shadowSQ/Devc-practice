#include <stdio.h>
const int STACK_INIT_SIZE = 100;
const int STACK_INCREMENT = 10;

typedef struct //
{
	int *elem; 				 //�洢����Ԫ�ص�����	  //Ҳ��ջ�����ͣ�������ʱ�޸� 
	int top;  				 //ջ��ָ�� 
	int stacksize;  	     //��ǰ����Ķ�ջ�������    ��selemtypeΪ��λ 
	int incrementsize;		 //Լ���������ռ�����Ҳ����selemtypeΪ��λ 
	
}stack;

void InitStack(stack &S,int maxsize = STACK_INIT_SIZE ,int incresize =  STACK_INCREMENT)
{
	//����һ����ջ����ʼ��������ռ�Ϊmaxsize,Ԥ�����������Ϊincresize
	S.elem = new int[maxsize];   //Ϊ˳��ջ��������ռ� 
	S.top = -1;					//��ǰ��������0 
	S.stacksize = maxsize;      //����Ϊ������� 
	S.incrementsize = incresize ; 
} 

bool stackempty(stack &S)
{
	if(S.top==-1)return true;
	return false;	
}

bool GetTop(stack &S,int &e)
{
	//��ջ���գ�eΪջ��Ԫ�أ���������true ����Ϊfalse
	if(S.top==-1)return false;
	else 
	e = S.elem[S.top];
	S.elem[0] = e;
	return true; 	
}
void Push(stack &S,int e)
{
//��ջ����
//���ջ��������׷������
if(S.top==S.stacksize-1)
{
	S.stacksize += S.incrementsize;
	S.elem = new int[S.incrementsize];
} 
else
{
	S.elem[++S.top] = e;
}

} 

bool Pop(stack &S,int &e)
{
	if(S.top==-1)return false;
	e = S.elem[S.top--];
	return true;
}

int main ()
{
	stack S;
	int n,x;
	int e=0;
	InitStack(S);//��ʼ����ջ
	scanf("%d %d",&n,&x) ;
	
	while(n)
	{
	Push(S,n%x);
	n = n/x;
	}
	
	while(!stackempty(S))
	{
	Pop(S,e);
	printf("%d",e);
	}
	
} 
