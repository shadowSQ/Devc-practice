#include <stdio.h>
#define unknown -1


int F(int i,int *knownF)
{
	int t;
	//如果该数值已知，则直接取用 
     if(knownF[i] != unknown){
        return knownF[i];
     }
     if(i == 0) t = 0;
     if(i == 1) t = 1;
     if(i > 1)  t = F(i - 1,knownF) + F(i - 2,knownF);
     return knownF[i] = t;
}
int main(){
	int n,i;
 	scanf("%d",&n);
 	int knownF[n];
 	
 	for(i=0;i<=n;i++)
	knownF[i] = -1;
	F(n,knownF);
	
	for(i=0;i<=n;i++)
	printf("%d ",knownF[i]);
	
	//printf("%d",);

} 
