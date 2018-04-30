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

// 
//����ջԪ������ 
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


//ʵ�����������Ĳ���
int InitRList(RList &a){
	a.elem = new Result[INIT_SIZE];
	if(!a.elem)return 0;
	a.top = -1;
	a.listsize  = INIT_SIZE;
	return 1;
}

int ClearRList(RList &a){
	//��ս������ 
	if(!a.elem)return 0;
	a.top = -1;
	return 1;
	
}

int EnElem(stack S,RList &a){
	//��ջ�еĽ⸴�Ƶ��������
	int i,j;
	if(!a.elem)return 0;
	if((a.top)==(a.listsize-1)){//����Ŀռ���������Ϊ���������ռ� 
		Result *temp = a.elem; //�ݴ�ͷָ�� 
		a.listsize+=ADD_SIZE;//��չ����  
		a.elem = new Result[a.listsize];//�����¿ռ� 
		if(!a.elem)return 0;
		
		for(i=0;i<=a.top;i++)
			for(j=0;j<=a.elem[i][0];j++) //a.elem[i][0]��һ���ĳ��ȣ������������� 
			a.elem[i][j] = temp[i][j];//���θ���ԭֵ 
			delete []temp;
	}
	
	a.top += 1;
	
	for(i=1;i<=StackLength(S);i++)
	 a.elem[a.top][i] = S.elem[i-1];//�õ�ջ�е�Ԫ�� 
	 
	 a.elem[a.top][0] = StackLength(S);
	 return 1;
} 

int SaveResult(stack S,double M,double vol,RList &r)
{
//��֤���������ֻ�������Ž�
if(vol>M)return 1;//�������Ž⣬������ 
 if (vol==M){EnElem(S,r);return 1;//ͬΪ���Ž⣬������ 
 }
 //�����Ψһ���Ž⣬����� ����֮���ڼ��룬������ֻ�����һ�����Ž� 
ClearRList(r);
EnElem(S,r);
return 1;
} 

int OutputResult(RList r){
	//������Ž����� 
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
	
	//�����㷨
//	printf("�����㷨");
	stack S;
	RList a;
	InitStack(S);
	InitRList(a);
	int count = 0,j = 0;
	//	printf("�����㷨push");
 //	Push(S,j);
		printf("�����㷨pushover");
	int totalCost = 1000;//��÷�����ʼֵ
	int v = 0;//��������ֵ
	printf("v:%d\n",v);
	bool job[MAX_D];
	for(i=0;i<=MAX_D+1;i++)job[i] = false;
	do{
		//
		while((StackLength(S)<=n)&&(j<=m-1)){//�����������˶������񣬲��һ����������ѡ��ʱ�� 
			if((cost.elem[StackLength(S)][j+1]!=0)&&(job[j]!=true)){//�жϽ���Ƿ�Ϸ� 
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
			//����õĽ⸴�Ƶ������� 
			SaveResult(S,totalCost,v,a);
			if(totalCost>v)totalCost = v;	
		}
		
		if(StackLength(S)>0){
			//��ջ����
			Pop(S,j);
				job[j]=false;
			{
				//	printf("After pop :StackLength(S):%d,j+1:%d,elem:%d\n",StackLength(S)+1,j+1,cost.elem[StackLength(S)+1][j+1]);		
				v= v-cost.elem[StackLength(S)][j+1];count-=1;
			} 
			
			
		j+=1;
		}
		
		
	}while((StackLength(S)>0)||(j<n));//ֻ�е�ջΪ�գ���������Ϊn+1��ʱ�������������n+1���Ǳ������ײ���
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
