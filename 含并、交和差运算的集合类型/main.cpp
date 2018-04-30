#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef int ElemType;//Ԫ������
typedef struct NodeType{
	ElemType data;
    struct NodeType *next;
}NodeType,*LinkType; 

typedef struct{
	LinkType head,tail;//�����б��ͷ����β���
	int size;
	int curpos;		//��ǰ��������Ԫ����������е�λ�� 
	LinkType current;//��ǰָ��	 
}OrderedList;


bool InitList(OrderedList &L)
{
	//����һ����ͷ���Ŀյ���������L��������true
	//������ʧ�ܣ���headͷָ��ΪNULL������false 
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
	//�������� 
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
	//���i��[1,maxsize]֮�䣬�򷵻������еĵ�i��Ԫ�أ�
	//���򷵻�һ���̶�ֵ
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
	//���������д�����e��ͬ��Ԫ�أ��򷵻�����������е�λ��
	//���򷵻�0 
	if(!L.head)
	return 0;
	if(e==L.current->data)	//��������뵱ǰλ�õ�ֵ��ȣ���ֱ�Ӵ��� 
	return L.curpos;
	if(e<L.current->data)	//������ڵ�ǰλ��ǰ��������С�ķ��򣩣����ͷָ�뿪ʼ�� 
	{	
	L.current = L.head;
	L.curpos = 0; 
	}

	while((L.current->next)&&(e>L.current->next->data)) //��δ��βָ���e����Ԫ�ص���ֵС��ʱ�� 
	{
		L.current = L.current->next;				//ָ����һ������ֵ 
		L.curpos++; 
	}
	if((!L.current->next)||(e<L.current->next->data))
	return 0;
	else return L.curpos+1;
}

void InsertElem(OrderedList &L,ElemType e)
{
	LinkType s;
	//��������в�������e��ͬ��Ԫ�أ����������
	//����֮��ָ��ָ��ող���Ľڵ�
	if(!LocatePos(L,e))
	{
		s = new NodeType;			//Ϊ�½ڵ����ռ� 
		s->data = e;				//�õ���ֵ 
		s->next = L.current->next;	//
		L.current->next = s;		//���� 
		if(L.tail==L.current)		//������֮�󣬷���ԭ����current��ʵ�Ѿ���βָ���� 
		L.tail = s;					//��������βָ��Ϊ s 
		
		L.current = s;				//����currentָ��ָ���½ڵ� 
		L.curpos++;					//����λ������ 
		L.size++;					//���Ԫ��������1 
	}	
} 

void DeleteElem(OrderedList &L,int i) 
{
	//ɾ�������L�ĵ�i��Ԫ��
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

void ListTraverse(OrderedList &L)//��������� 
{
	LinkType p;
	if(L.head){
		p = L.head->next;
		while(p){
			Output(p);p = p->next;
		}
	}
}

//����������������OrderedList���弯����Set������OrderedSet 
typedef OrderedList OrderedSet;

bool CreateEmptySet(OrderedSet &T)
{
	//����һ���ռ��� 
	if(InitList(T))
	return true;
	else
	return false;
}

void DestorySet(OrderedSet &T)
{
	//����һ������
	DestoryList(T); 
	
}

void AddElem(OrderedSet &T,ElemType e)
{
	//���e���ڼ����ڣ�����룬����Ϊ�ղ��� 
//	if(e>0)
	InsertElem(T,e);
}
void Deletelem(OrderedSet &T,ElemType e)
{
	//�������д��ں�e��ͬ����ֵ����ɾ��������Ϊ�ղ��� 
	if(LocatePos(T,e))
	DeleteElem(T,LocatePos(T,e));
	
}

int GetSetLength(OrderedList &T)
{
	//��ü��ϵ�Ԫ�ظ��� 
	return T.size;
} 

void Union(OrderedSet &T,OrderedSet &S1,OrderedSet &S2)
{
	//���������ϵĲ��� 
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
	//���������ϵĽ��� 
	CreateEmptySet(T);
	ElemType a ;//�ݴ�Ԫ�� 
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
	//���������ϵĲ��	 S1-S2
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
		
		if(ib > Nb)//����Ǳ�����������Ϊ�������У����� ������Ԫ�� 
		{ib = 1;AddElem(T,tempa);}
		else 
		continue;
		
	}//while ia
	 
	 
	
}
void CreateSet(OrderedSet &ST)
{
	//������ֵ�������˼��� 
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
	//��ӡ�������� 
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


