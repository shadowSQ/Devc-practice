#include <stdio.h> 
#define INIT_SIZE 100
#define MAX_D 10
#define ADD_SIZE 10

//ջ�Ķ���
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

void back(int w[],int T,int n)
{
	//���������T 
	stack S;
	int i;
	int k = 0;
	InitStack(S);
	 do
	 {
	 
	 while((T>0)&&(k<n)){
	 	if(T-w[k]>=0){
	 	//	printf("\n%d\n",k);
	 		Push(S,k);T -= w[k];
	 	}
	 	k++;	
	 }
	 if(T==0){
	 	for(i=0;i<S.top+1;i++)
	 	{
	 		printf("%d",S.elem[i]+1);
	 	}
	 	printf("\n");
		 }
		 
	 	Pop(S,k);
		T+=w[k];
	 	k++;
	 
	 	
	 }while((!stackempty(S))||(k<n));
}
// 
int main(){
	int i;
	int w[6],T=10;
	for(i=0;i<6;i++)
	scanf("%d",&w[i]);

	back(w,T,6);
	
	
}
