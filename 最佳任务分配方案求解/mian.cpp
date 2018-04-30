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

// 
//定义栈元素类型 
typedef int ElemType;
typedef struct {
	ElemType *elem;
	int top;
	int stacksize;
}Stack;

typedef int Result[MAX_D+1];
typedef struct {
	Result *elem;
	int listsize;
	int top;
}RList;

int StackLength(stack &S)
{
	return S.top+1;
}


//实现问题解数组的操作
int InitRList(RList &a){
	a.elem = new Result[INIT_SIZE];
	if(!a.elem)return 0;
	a.top = -1;
	a.listsize  = INIT_SIZE;
	return 1;
}

int ClearRList(RList &a){
	//清空解的数组 
	if(!a.elem)return 0;
	a.top = -1;
	return 1;
	
}

int EnElem(stack S,RList &a){
	//将栈中的解复制到解的数组
	int i,j;
	if(!a.elem)return 0;
	if((a.top)==(a.listsize-1)){//当解的空间已满重新为此数组分配空间 
		Result *temp = a.elem; //暂存头指针 
		a.listsize+=ADD_SIZE;//扩展容量  
		a.elem = new Result[a.listsize];//分配新空间 
		if(!a.elem)return 0;
		
		for(i=0;i<=a.top;i++)
			for(j=0;j<=a.elem[i][0];j++) //a.elem[i][0]是一组解的长度，所以用做界限 
			a.elem[i][j] = temp[i][j];//依次赋予原值 
			delete []temp;
	}
	
	a.top += 1;
	
	for(i=1;i<=StackLength(S);i++)
	 a.elem[a.top][i] = S.elem[i-1];//得到栈中的元素 
	 
	 a.elem[a.top][0] = StackLength(S);
	 return 1;
} 

int SaveResult(stack S,double M,double vol,RList &r)
{
//保证解的数组中只存入最优解
if(vol>M)return 1;//不是最优解，不操作 
 if (vol==M){EnElem(S,r);return 1;//同为最优解，入数组 
 }
 //如果是唯一最优解，则清空 数组之后，在加入，这样就只存放有一个最优解 
ClearRList(r);
EnElem(S,r);
return 1;
} 

int OutputResult(RList r){
	//输出最优解数组 
	int i,j;
	if(r.top==-1){
		printf("no answer");
		return 1;
	}
	for(i=0;i<=r.top;i++){
		printf("\n");
		for(j=1;j<=r.elem[i][0];j++)
		printf("%d",r.elem[i][j]);
	}
	return 1;
} 

void BackTracking(RList &cost,int n,int m)
{
	int i;
	
	//回溯算法
//	printf("回溯算法");
	stack S;
	RList a;
	InitStack(S);
	InitRList(a);
	int count = 0,j = 0;
	//	printf("回溯算法push");
 //	Push(S,j);
		printf("回溯算法pushover");
	int totalCost = 1000;//最好方案初始值
	int v = 0;//经费消耗值
	printf("v:%d\n",v);
	bool job[MAX_D];
	for(i=0;i<=MAX_D+1;i++)job[i] = false;
	do{
		//
		while((StackLength(S)<=n)&&(j<=m-1)){//当不是所有人都有任务，并且还有任务可以选的时候 
			if((cost.elem[StackLength(S)][j+1]!=0)&&(job[j]!=true)){//判断结点是否合法 
				//	printf("StackLength(S):%d,j+1:%d,elem:%d\n",StackLength(S)+1,j+1,cost.elem[StackLength(S)][j+1]);
					
				Push(S,j);	
				v=v+cost.elem[StackLength(S)-1][j+1];count +=1;
				job[j]=true;//if(j!=0)
			//	printf("StackLength(S):%d,j+1:%d,elem:%d\n",StackLength(S)+1,j+1,cost.elem[StackLength(S)-1][j+1]);			
			//	printf("v:%d\n",v);
				j=0;
				
			}
			else 
			j+=1;	
		}
		if((StackLength(S)>=m)&&(count==n)){
			//将求得的解复制到解数组 
			SaveResult(S,totalCost,v,a);
			if(totalCost>v)totalCost = v;	
		}
		
		if(StackLength(S)>0){
			//退栈回溯
			Pop(S,j);
				job[j]=false;
			{
				//	printf("After pop :StackLength(S):%d,j+1:%d,elem:%d\n",StackLength(S)+1,j+1,cost.elem[StackLength(S)+1][j+1]);		
				v= v-cost.elem[StackLength(S)][j+1];count-=1;
			} 
			
			
		j+=1;
		}
		
		
	}while((StackLength(S)>0)||(j<n));//只有当栈为空，并且树深为n+1的时候结束，树深至n+1则是遍历到底部了
	 printf("ok\n");
	 printf("%d",totalCost);
	OutputResult(a);
	
} 


int main(){
	
	int n,m;
	int i,j;
	RList cost;
	InitRList(cost);
	
	printf("plese input personnumbers\n");
	scanf("%d",&n);
	printf("plese input testnumbers\n");
	scanf("%d",&m);
		for(i=0;i<n;i++){
		cost.elem = new Result[m+1];		
	}
	
	for(i=0;i<n;i++){
		for(j=1;j<m+1;j++)
		{
		scanf("%d",&cost.elem[i][j]);
		}
	cost.top +=1;	
	}
	
		for(i=0;i<n;i++){
		cost.elem[i][0]=-1;	
	}
	
	
	for(i=0;i<n;i++){
		for(j=1;j<m+1;j++)
		{
		printf("%d",cost.elem[i][j]);
		}	
	}
	BackTracking(cost,n,m);
}//mian
