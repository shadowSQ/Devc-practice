#include <stdio.h>
#include <string.h>
int main()

{
	char * p ;				//字符指针 
	char s[5]={"adce"};		//字符数组
	
	p = s;
	char *p1;
	printf("s字符串：\n");
	printf("%s\n",s);

	printf("s的首地址：\n");	
		
	printf("%d\n",s);		//s的首地址 
	printf("%d\n",&s[0]);	//s的首地址 
	printf("%d\n",p);		//s的首地址 
	
	printf("s[1]的地址：\n");		
	
	printf("%d\n",s+1);		//s[1]的地址 
	printf("%d\n",&s[1]);	//s[1]的地址 
	printf("%d\n",p+1);		//s[1]的地址 
	
	printf("s的首地址 的元素： \n");	
	
	printf("%c\n",*s);		//s的首地址 的元素 
	printf("%c\n",s[0]);	//s的首地址 的元素 
	printf("%c\n",*p);		//s的首地址 的元素 
	
	printf("s[0]的地址 的元素ascii码+1的元素： \n");	
	 
	printf("%c\n",*s+1);	//s[0]的首地址 ascii码+1 的元素 
	printf("%c\n",s[0]+1);	//s[0]的首地址 ascii码+1 的元素 
	printf("%c\n",*p+1);	//s[0]的首地址 ascii码+1 的元素  
		printf("%c\n",++*p);   //指针后移，而不是值加1 
      printf("%c\n",++(*p));
	printf("s[1]的地址 的元素 \n");	
	 
	printf("%c\n",*(s+1));	//s[1]的首地址 的元素 
	printf("%c\n",s[1]);	//s[1]的首地址 的元素 
	printf("%c\n",*(p+1));	//s[1]的首地址 的元素  

    printf("%c\n",p[1]);    //s[1]的首地址 的元素  
    
    //重点记住：p[1]==*(p+1)，而不是固定位置 
//	printf("%c\n",*++p);	//s[1]的首地址 的元素  
//	printf("%c\n",*p++);	//s[1]的首地址 的元素  

	p1 = p+2;
	printf("%c\n",*p1);	//
	printf("%d\n",p1);	//
//	printf("%c",*p);
//	p = p+1;
//		printf("%c",*p);

		
} 
