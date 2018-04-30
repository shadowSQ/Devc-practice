#include <stdio.h>
  #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
int L(int a[6])
{
	int t;
	t = a[0];
	a[0] = a[2];
	a[2] = a[1];
	a[1] = a[3];
	a[3] = t;
	return a[6]; 
}
int R(int a[6])
{
	int t;
	t = a[0];
	a[0] = a[3];
	a[3] = a[1];
	a[1] = a[2];
	a[2] = t;
	return a[6]; 
}
int F(int a[6])
{
	int t;
	t = a[2];
	a[2] = a[4];
	a[4] = a[3];
	a[3] = a[5];
	a[5] = t;
	return a[6]; 
}
int B(int a[6])
{
	int t;
	t = a[2];
	a[2] = a[5];
	a[5] = a[3];
	a[3] = a[4];
	a[4] = t;
	return a[6]; 
}
int A(int a[6])
{
	int t;
	t = a[0];
	a[0] = a[4];
	a[4] = a[1];
	a[1] = a[5];
	a[5] = t;
	return a[6]; 
}
int C(int a[6])
{
	int t;
	t = a[0];
	a[0] = a[5];
	a[5] = a[1];
	a[1] = a[4];
	a[4] = t;
	return a[6]; 
}
int main()
{  
    int i;
    char st[50];
      int a[6]={1,2,3,4,5,6};
	  printf("%d%d%d%d%d%d\n",a[0],a[1],a[2],a[3],a[4],a[5]);

while(1)
{    	scanf("%s",&st);


    for(i=0;i<=50;i++)
    {
	switch(st[i])
	{
		case 'L' : a[6] = L(a);break;
		case 'R' : a[6] = R(a);break;
		case 'F' : a[6] = F(a);break;
		case 'B' : a[6] = B(a);break;
		case 'A' : a[6] = A(a);break;
		case 'C' : a[6] = C(a);break;
	}
	 }
	 for(i=0;i<=5;i++)
	 printf("%d",a[i]);
}

}
