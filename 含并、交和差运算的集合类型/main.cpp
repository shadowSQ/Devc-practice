#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef int ElemType;//元素类型
typedef struct NodeType{
	ElemType data;
    struct NodeType *next;
}NodeType,*LinkType; 

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

void InsertElem(OrderedList &L,ElemType e)
{
	LinkType s;
	//若有序表中不存在与e相同的元素，则有序插入
	//插入之后，指针指向刚刚插入的节点
	if(!LocatePos(L,e))
	{
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
	printf("%d,",p->data);
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

//利用有序链表类型OrderedList定义集合类Set，名称OrderedSet 
typedef OrderedList OrderedSet;

bool CreateEmptySet(OrderedSet &T)
{
	//创建一个空集合 
	if(InitList(T))
	return true;
	else
	return false;
}

void DestorySet(OrderedSet &T)
{
	//销毁一个集合
	DestoryList(T); 
	
}

void AddElem(OrderedSet &T,ElemType e)
{
	//如果e不在集合内，则插入，否则为空操作 
//	if(e>0)
	InsertElem(T,e);
}
void Deletelem(OrderedSet &T,ElemType e)
{
	//若集合中存在和e相同的数值，则删除，否则为空操作 
	if(LocatePos(T,e))
	DeleteElem(T,LocatePos(T,e));
	
}

int GetSetLength(OrderedList &T)
{
	//获得集合的元素个数 
	return T.size;
} 

void Union(OrderedSet &T,OrderedSet &S1,OrderedSet &S2)
{
	//求两个集合的并集 
	CreateEmptySet(T);
	S1.current = S1.head->next;
	S1.curpos = 1;
	while(S1.current)
	{
		AddElem(T,S1.current->data);
		S1.current = S1.current->next;
		S1.curpos++;
		
	}
	S2.current = S2.head->next;
	S2.curpos = 1;
	while(S2.current)
	{
		AddElem(T,S2.current->data);
		S2.current = S2.current->next;
		S2.curpos++;
	}//while
	
} 

void Intersection(OrderedSet &T,OrderedSet &S1,OrderedSet &S2)
{
	//求两个集合的交集 
	CreateEmptySet(T);
	ElemType a ;//暂存元素 
	ElemType b ;
	
	int ia=1,ib=1;
	
	int Na = GetSetLength(S1);
	int Nb = GetSetLength(S2);
	
	while((ia<=Na)&&(ib<=Nb)){
	a	= GetElem(S1,ia);
	b	= GetElem(S2,ib);
	
	if(a==b){
		AddElem(T,a);
	}//if
	
	if(a<=b)
	ia++;
	else 
	ib++;
	
	}//while
}

void Difference(OrderedSet &T,OrderedSet &S1,OrderedSet &S2) 
{
	//求两个集合的差集合	 S1-S2
	CreateEmptySet(T);
	ElemType tempa;
	ElemType b;
	
	int ia = 1,ib = 1;
	
	int Na = GetSetLength(S1);
	int Nb = GetSetLength(S2);
	
	while(ia<=Na){
		
		tempa = GetElem(S1,ia);
		b = GetElem(S2,ib);
		while((tempa != b)&&ib<=Nb){
			ib++;
			b = GetElem(S2,ib);		
		}//while ib
		
		ia++;
		
		if(ib > Nb)//如果是遍历结束，则为插入差集合中，否则 放弃该元素 
		{ib = 1;AddElem(T,tempa);}
		else 
		continue;
		
	}//while ia
	 
	 
	
}
void CreateSet(OrderedSet &ST)
{
	//输入数值并创建此集合 
	CreateEmptySet(ST);
	ElemType e;
	scanf("%d",&e);
	while(e!= -1)
	{
		AddElem(ST,e);
		scanf("%d",&e);
	}//while
}//CreateSet

void PrintSet(OrderedSet &T)
{
	//打印集合内容 
	printf("{");
	ListTraverse(T);
	printf("}");
	
} 

int main(int argc, char *argv[]) {
	
	OrderedSet S1,S2;
	OrderedSet UnionS,IntersectionS,DifferenceS;
	printf("Plese input S1\n");
	CreateSet(S1);
	printf("Plese input S2\n");
	CreateSet(S2);
	printf("S1:");
	PrintSet(S1);
	printf("\n");
	printf("S2:");
	PrintSet(S2);
	printf("\n");
	
	Union(UnionS,S1,S2);
	printf("Union:\n");
    PrintSet(UnionS);
    printf("\n");
    
    Intersection(IntersectionS,S1,S2);
    printf("Intersection:\n");
    PrintSet(IntersectionS);
    printf("\n");
    
    Difference(DifferenceS,S1,S2);
    printf("Difference:\n");
    PrintSet(DifferenceS);
    printf("\n");
    
    
	return 0;
}//main


