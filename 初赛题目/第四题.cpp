#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>  
using namespace std;

/*int find_sub_string(const std::string& str1, const string& str2);

Input:
2
abcdefg
bcd
abcdcdc
cdc
aaaaa
aaa

Output:
1
2
3*/ 

int find_sub_string(const std::string& str1, const string& str2,int n1,int n2){
	int i;
	int overcount=0;
	int flag =1; 
	int idec[n1],counti=0;
	
//	for(i=0;i<n1;i++)
	
//	printf("%c ",str1[i]);
//	printf("\n");
//	for(i=0;i<n2;i++)
//	printf("%c ",str2[i]);
//	printf("\n");
	//查看字符串是否正确
	 
//	printf("n1：%d",n1);
//	printf("n2：%d",n2);
	//长度
	
//	printf("\n");
	
	if(n2==1)
	{
		for(i=0;i<n1;i++)
			if(str1[i]==str2[0])
				overcount++;
		return overcount;
	}
	else
	{
		for(i=0;i<n1;i++)
		{
			if(str1[i]==str2[0])
			{
				idec[counti]=i;
				counti++;
			}	//记录可能出现的位置
		}
		while(counti--)
		{
			
			flag =1; 		
			for(i=idec[counti];i<idec[counti]+n2;i++)
			{
				
				if(n1<idec[counti]+n2)
					{
					flag=0;	
					break;
					}
				
				if(str1[i]!=str2[i-idec[counti]])
					{
					flag=0;	
					break;
					}
				 
			}			 
			//一次对比结束后如果成功flag==1
			//进行下一次 
			if (flag==1)
			overcount++;			 
		}//while
			 		
	}//else
	 return overcount;
}

int main(){
	int T;
	int i;
	scanf("%d",&T);
	int x;
	char a[100];
	char b[100];
	
	while(T--)
	{
	scanf("%s",&a);
	scanf("%s",&b);
 	x=find_sub_string(a, b,strlen(a),strlen(b));
 	printf("%d\n",x);
	}
	
	
	
	
	return 0;

}

