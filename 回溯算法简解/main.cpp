#include <stdio.h> 
#define INIT_SIZE 100
#define MAX_D 10
#define ADD_SIZE 10

//栈的定义
const int STACK_INIT_SIZE = 100;
const int STACK_INCREMENT = 10;

typedef struct //
{
	int *elem; 				 //存储数据元素的数组	  //也是栈的类型，可以随时修改 
	int top;  				 //栈顶指针 
	int stacksize;  	     //当前分配的堆栈最大容量    以selemtype为单位 
	int incrementsize;		 //约定的增补空间量，也是以selemtype为单位 
	
}stack;

void InitStack(stack &S,int maxsize = STACK_INIT_SIZE ,int incresize =  STACK_INCREMENT)
{
	//构造一个空栈，初始分配的最大空间为maxsize,预设的扩容增量为incresize
	S.elem = new int[maxsize];   //为顺序栈分配数组空间 
	S.top = -1;					//当前所含个数0 
	S.stacksize = maxsize;      //容量为最大容量 
	S.incrementsize = incresize ; 
} 



bool stackempty(stack &S)
{
	if(S.top==-1)return true;
	return false;	
}

bool GetTop(stack &S,int &e)
{
	//若栈不空，e为栈顶元素，函数返回true 否则为false
	if(S.top==-1)return false;
	else 
	e = S.elem[S.top];
	return true; 	
}
void Push(stack &S,int e)
{
//入栈操作
//如果栈已满。则追加容量
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
	//背包总体积T 
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
