#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef int ElemType;//元素类型
typedef struct NodeType{
	ElemType data;
    struct NodeType *next;
}NodeType,*LinkType; 
	LinkType t;
	LinkType ttemp;
typedef struct{
	LinkType head,tail;//有序列表的头结点和尾结点
	int size;
	int curpos;		//当前被操作的元素在有序表中的位置 
	LinkType current;//当前指针	 
}OrderedList;


bool InitList(OrderedList &L)
{
	//构造一个带头结点的空的有序链表L，并返回true
	//若分配失败，令head头指针为NULL，返回false 
	L.head = new NodeType; 
	if(!L.head)return false;
	L.head->data = 0;
	L.head->next = NULL;
	L.current = L.tail = L.head;
	L.curpos = L.size = 0;
	return true;
}

void DestoryList(OrderedList &L)
{
	//销毁链表 
	LinkType p;
	while(L.head->next)
	{
		p = L.head->next;
		L.head->next = p->next;
		delete p;
	}
	delete L.head;
} 

ElemType GetElem(OrderedList &L,int i)
{
	//如果i在[1,maxsize]之间，则返回链表中的第i个元素，
	//否则返回一个固定值
	if((i<1)||(i>L.size)) 
	return 0;
	if(i==L.curpos)
	return L.current->data;
	if(i<L.curpos)
	{L.curpos=0;L.current = L.head;} 
	else
	{
		L.curpos++;L.current = L.current->next; 
	}
	while(L.curpos<i)
	{
		L.curpos++;L.current = L.current->next; 
	}
	return L.current->data;
} 

int LocatePos(OrderedList &L,ElemType e)
{	
	//如果有序表中存在于e相同的元素，则返回他再有序表中的位置
	//否则返回0 
	if(!L.head)
	return 0;
	if(e==L.current->data)	//如果正好与当前位置的值相等，则直接处理 
	return L.curpos;
	if(e<L.current->data)	//如果是在当前位置前方，（往小的方向），则从头指针开始找 
	{	
	L.current = L.head;
	L.curpos = 0; 
	}

	while((L.current->next)&&(e>L.current->next->data)) //当未到尾指针和e还比元素的数值小的时候 
	{
		L.current = L.current->next;				//指向下一个有序值 
		L.curpos++; 
	}
	if((!L.current->next)||(e<L.current->next->data))
	return 0;
	else return L.curpos+1;
}
int LocatePos2(OrderedList &L,int k)
{	
	//如果有序表中存在于e相同的元素，则返回他再有序表中的位置
	//否则返回0 
	if(!L.head)
	return 0;
	L.current = L.head ;
	L.curpos = -1;
	while(k--)
	{
		L.current = L.current->next;				//指向下一个有序值 
		L.curpos++; 
	}
	printf("L.curpos+1:%d,",L.curpos+1);
	return L.curpos+1;
}
void InsertElem(OrderedList &L,ElemType e)
{
	LinkType s;
	//若有序表中不存在与e相同的元素，则有序插入
	//插入之后，指针指向刚刚插入的节点
	
		s = new NodeType;			//为新节点分配空间 
		s->data = e;				//得到数值 
		s->next = L.current->next;	//
		L.current->next = s;		//插入 
		if(L.tail==L.current)		//若插入之后，发现原来的current其实已经到尾指针了 
		L.tail = s;					//则必须更改尾指针为 s 
		
		L.current = s;				//更改current指针指向新节点 
		L.curpos++;					//更改位置数据 
		L.size++;					//表的元素数量加1 
		
} 

void DeleteElem(OrderedList &L,int i) 
{
	//删除有序表L的第i个元素
	 if((i>=1)&&(i<=L.size))
	 {
	 	ElemType pre = GetElem(L,i-1);
	 	LinkType p = L.current->next;
	 	L.current->next = p->next;
	 	if(L.tail==p)
	 	L.tail=L.current;
	 	delete p;
	 	L.size--;
	 }
}

void Output(LinkType p)
{
	printf("%d ",p->data);
} 
void reverse(OrderedList &L,int k)
{

	if(!L.head)
	return ;
	int kt=k;
	L.current= L.head;	
	L.curpos = 0;
	
	while(k--)
	{
		if(L.curpos == 0 )
		{
			t = L.head->next;
			L.current = L.current->next->next;
			L.curpos++;
		}
		else
		{
			ttemp = L.current;		
			L.current=L.current->next;		
			ttemp->next = t;		
			t = ttemp;
			L.curpos++;
			
		}
	//	printf("L.curpos:%d,",L.curpos);
	//	printf("curdata:%d,",L.current->data);
	}
	        if(kt!=1)
	        {
	        L.head->next->next= L.current;
			L.head->next = ttemp;
	        }
}
void ListTraverse(OrderedList &L)//遍历有序表 
{
	LinkType p;
	if(L.head){
		p = L.head->next;
		while(p){
			Output(p);p = p->next;
		}
	}
}

int main(){
	
	int T;
	int i;
	scanf("%d",&T);
//	if(T<1||T>10)
//	return 0;
	
	while(T--)
	{
		int n,k;
		scanf("%d",&n);
		
		int linkC[n];
		for(i=0;i<n;i++)
		scanf("%d",&linkC[i]);
		
		OrderedList L;
		InitList(L);
		
		for(i=0;i<n;i++)
		InsertElem(L,linkC[i]);
		
	//	ListTraverse(L);
		
		scanf("%d",&k);
		
		int chushu;
		 chushu= n/k;
		int yushu ;
		yushu= n%k;
		
	//	printf("chushu:%d yushu:%d:",chushu,yushu);
			
		OrderedList temL;
		InitList(temL);
		temL = L;
		LinkType p;
		LinkType t2;
		for(i=0;i<chushu;i++)
		{
			
			int kt = k;
			if(i==0)
			{
				p = L.head->next;
				
				while(kt-->1)
				{
				p=p->next;	
			//	printf("p->data:%d ",p->data);
				}
				
				t2 = p->next;
		//		printf("t->data:%d ",t2->data);
				p->next = NULL;
				
				reverse(L,k);
				ListTraverse(L);
					
			}
			else{
				L.head->next = t2;
				p = L.head->next;
				
				while(kt-->1)
				{
				p=p->next;	
			//	printf("p->data:%d ",p->data);
				}
				
				t2 = p->next;
				
				p->next = NULL;
				
				reverse(L,k);
				ListTraverse(L);
				
			}
	
		}//for
		if(k>n)
			{
				reverse(L,n);
				ListTraverse(L);	
			}
			else if(yushu==0)
			return 0;
			else
			{
				int yushut= yushu;
				L.head->next = t2;
				p = L.head->next;	
				while(yushu-->1)
				{
				p=p->next;	
			//	printf("p->data:%d ",p->data);
				}		
				t2 = p->next;			
				p->next = NULL;	
				reverse(L,yushut);
				ListTraverse(L);	
			}
		
	//	reverse(L,k);
	//	ListTraverse(L);
	
	}
	return 0;
} 
