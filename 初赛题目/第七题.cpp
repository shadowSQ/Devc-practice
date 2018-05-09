#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
/*   给定一个全小写的英文字符串，
请在该字符串中找到一个连续子字符串，
使得子字符串没有重复的字符并且长度最长，
计算此最长字符串的长度。比如：abcbdeab,最长的子字符串为cbdea，
长度为5；aaaa，最长子字串为a，长度为1。  */
int maxcount=0;
int notcas(char *temp,char si,int nt)
{	int i;
	for(i=0;i<nt;i++)
	{
		if(temp[i]==si)
		return 0;
	}
	return 1;
}

void Opera(char *s,int n,int start){
	//string ：s ，length：n 
	char temp[n];
	int count=0,nt = 0;
	int i;
	for(i=start;i<n;i++)
	{
		if(notcas(temp,s[i],nt))//当子字符串跟下一个字母无重复时 
		{
			temp[nt]=s[i];//放入子字符串 
			nt++;//子字符串长度加1	
			count++;
		} 
		else
		{
			nt = 0;//子字符串清零 
		//	printf("count=%d \n",count);
			
			if(maxcount<count)
			maxcount=count;
			count=0;
			
			return ;
		}
	}
//	printf("count=%d \n",count);
	
	if(maxcount<count)
		maxcount=count;
}
int main(){

	int T;
	int i;
	scanf("%d",&T);
	while(T--)
	{
		maxcount= 0 ;
char a[32];
char b[32];

	scanf("%s",&a);
	for(i=0;i<strlen(a);i++)
	{
	Opera(a,strlen(a),i); 
	}
    printf("%d \n",maxcount);
	}

return 0;
}
