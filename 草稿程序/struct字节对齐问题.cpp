#include <stdio.h> 
#pragma pack(1)//ǿ�Ʋ����� 
struct s {
char ch;
int i;
};

int main()
{
	
	printf("%d", sizeof(struct s));
}
