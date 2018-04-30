#include <stdio.h>
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
	S.elem[0] = e;
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
    	
    	//列表标记 
    	//第一种情况，为第一个房子 
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
    	 }//如果是第一个房子， 对她的后面一个和最后一个进行记录， 
    	 
    	}
    	//第二种情况，为最后一个房子 
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
    	 }//如果是最后一个房子， 对她的前面和第一个进行记录 
    	}
    	//普通情况，中间房子 
    	else
    	{
    		if(*(q+i+1) == -1)
    	 flaghou = 1;
    	 else 
    	 {flaghou = 0;
    	 *(q+i+1) = -1;
    	 }//前面如果没有屏蔽，则做记录，然后屏蔽 ，如果已经屏蔽了，则记录 
    	 	
    	if(*(q+i-1) == -1)
    	 flagqian = 1;
    	 else 
    	 {flagqian = 0;
    	 *(q+i-1) = -1;
    	 }//后面如果没有屏蔽，则做记号，然后屏蔽 ，如果已经屏蔽了，则记录 
    	}//标记完毕 
    
    	count1 = count1 + *(p+i);
    	
  printf("\n after push");
  for(j=0;j<n;j++)
 {
	printf("%d ",*(q+j));
  }  
  printf("\n");//入栈后的数据查看
   
    	check(n,p,q,S);//遍历 
    	
    	
    
    	
		*(q+i) = 0;//表示可以贩卖，归0 
		
		if(i==0) //第一个房子，回溯标记 
		{
			if(flagqian == 0)
			*(q+n-1) = 0;
			if(flaghou == 0)
			*(q+i+1) = 0;
		}
		else if(i==n-1) //最后一个房子，回溯标记 
		{
			if(flaghou == 0)
			*(q) = 0;
			if(flagqian == 0)
			*(q+i-1) = 0;
		}
    	else//普通情况，回溯标记 
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
        
        //列表 
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
