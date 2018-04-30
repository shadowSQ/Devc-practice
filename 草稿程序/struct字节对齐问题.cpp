#include <stdio.h> 
#pragma pack(1)//强制不对齐 
struct s {
char ch;
int i;
};

int main()
{
	
	printf("%d", sizeof(struct s));
}
