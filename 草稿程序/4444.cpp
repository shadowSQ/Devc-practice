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

int choice = 0;
int count1=0,temp=0;

int check(int n,int *p,int *q,stack &S)
{
	int i;
    int j;
    int e;
    int flag=0;
    
    int flagqian,flaghou;
     for(i =0;i<n;i++)
    {if(*(q+i)!=-1)flag =1;
	}
	if(flag ==0)
	{
		if(temp<=count1)
		{
			temp = count1;
		return 0;
		}
		else
		return 0;
	}
	
    
    for(i =0;i<n;i++)
    {
    	if(*(q+i) != -1)
    	{
    	
    		
    	*(q+i) = -1;
    	
    	//�б��� 
    	//��һ�������Ϊ��һ������ 
    	if(i==0)
    	{
			if(*(q+i+1) == -1)
    		 flaghou = 1;
    		 else 
    		 {flaghou = 0;
    		 *(q+i+1) = -1;
    		 }
    	 
    
			if(*(q+n-1) == -1)
    		 flagqian = 1;
    		 else 
    		 {flagqian = 0;
    		 *(q+n-1) = -1;
    	 }//����ǵ�һ�����ӣ� �����ĺ���һ�������һ�����м�¼�� 
    	 
    	}
    	//�ڶ��������Ϊ���һ������ 
    	else if(i==n-1)
    	{
		if(*(q+i-1) == -1)
    	 flagqian = 1;
    	 else 
    	 {flagqian = 0;
    	 *(q+i-1) = -1;
    	 }
    	 
    	 
		if(*(q) == -1)
    	 flaghou = 1;
    	 else 
    	 {flaghou = 0;
    	 *(q) = -1;
    	 }//��������һ�����ӣ� ������ǰ��͵�һ�����м�¼ 
    	}
    	//��ͨ������м䷿�� 
    	else
    	{
    		if(*(q+i+1) == -1)
    	 flaghou = 1;
    	 else 
    	 {flaghou = 0;
    	 *(q+i+1) = -1;
    	 }//ǰ�����û�����Σ�������¼��Ȼ������ ������Ѿ������ˣ����¼ 
    	 	
    	if(*(q+i-1) == -1)
    	 flagqian = 1;
    	 else 
    	 {flagqian = 0;
    	 *(q+i-1) = -1;
    	 }//�������û�����Σ������Ǻţ�Ȼ������ ������Ѿ������ˣ����¼ 
    	}//������ 
    
    	count1 = count1 + *(p+i);
    	
  printf("\n after push");
  for(j=0;j<n;j++)
 {
	printf("%d ",*(q+j));
  }  
  printf("\n");//��ջ������ݲ鿴
   
    	check(n,p,q,S);//���� 
    	
    	
    
    	
		*(q+i) = 0;//��ʾ���Է�������0 
		
		if(i==0) //��һ�����ӣ����ݱ�� 
		{
			if(flagqian == 0)
			*(q+n-1) = 0;
			if(flaghou == 0)
			*(q+i+1) = 0;
		}
		else if(i==n-1) //���һ�����ӣ����ݱ�� 
		{
			if(flaghou == 0)
			*(q) = 0;
			if(flagqian == 0)
			*(q+i-1) = 0;
		}
    	else//��ͨ��������ݱ�� 
		{
		if(flagqian == 0) 
    	*(q+i-1) = 0;
    	if(flaghou == 0) 
    	*(q+i+1) = 0;
    	}
    	
    printf("\n after pop");
    for(j=0;j<n;j++)
    {
	printf("%d ",*(q+j));
   }  
    printf("\n");
    	count1 = count1 - *(p+i);
    	
    	}
    }
}

int main()
{
    int t,n;
    int i = 0;
    int j = 0;
    stack S;
    InitStack(S);
    scanf("%d",&t);
    
    for(j=0;j<t;j++)
    {
    scanf("%d",&n);
        
    int *p;
    p = new int[n];
        
        //�б� 
       int *q;
    q = new int[n];
       for(i=0;i<n;i++)
    {
    	*(q+i) = 0;
    }  
    

    for(i=0;i<n;i++)
    {
    	scanf("%d",p+i);
    }
    
    check(n,p,q,S);
      printf("%d\n",temp);
    
 }
}
