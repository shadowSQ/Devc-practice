#include <stdio.h>
#include <string.h>
int main()

{
	char * p ;				//�ַ�ָ�� 
	char s[5]={"adce"};		//�ַ�����
	
	p = s;
	char *p1;
	printf("s�ַ�����\n");
	printf("%s\n",s);

	printf("s���׵�ַ��\n");	
		
	printf("%d\n",s);		//s���׵�ַ 
	printf("%d\n",&s[0]);	//s���׵�ַ 
	printf("%d\n",p);		//s���׵�ַ 
	
	printf("s[1]�ĵ�ַ��\n");		
	
	printf("%d\n",s+1);		//s[1]�ĵ�ַ 
	printf("%d\n",&s[1]);	//s[1]�ĵ�ַ 
	printf("%d\n",p+1);		//s[1]�ĵ�ַ 
	
	printf("s���׵�ַ ��Ԫ�أ� \n");	
	
	printf("%c\n",*s);		//s���׵�ַ ��Ԫ�� 
	printf("%c\n",s[0]);	//s���׵�ַ ��Ԫ�� 
	printf("%c\n",*p);		//s���׵�ַ ��Ԫ�� 
	
	printf("s[0]�ĵ�ַ ��Ԫ��ascii��+1��Ԫ�أ� \n");	
	 
	printf("%c\n",*s+1);	//s[0]���׵�ַ ascii��+1 ��Ԫ�� 
	printf("%c\n",s[0]+1);	//s[0]���׵�ַ ascii��+1 ��Ԫ�� 
	printf("%c\n",*p+1);	//s[0]���׵�ַ ascii��+1 ��Ԫ��  
		printf("%c\n",++*p);   //ָ����ƣ�������ֵ��1 
      printf("%c\n",++(*p));
	printf("s[1]�ĵ�ַ ��Ԫ�� \n");	
	 
	printf("%c\n",*(s+1));	//s[1]���׵�ַ ��Ԫ�� 
	printf("%c\n",s[1]);	//s[1]���׵�ַ ��Ԫ�� 
	printf("%c\n",*(p+1));	//s[1]���׵�ַ ��Ԫ��  

    printf("%c\n",p[1]);    //s[1]���׵�ַ ��Ԫ��  
    
    //�ص��ס��p[1]==*(p+1)�������ǹ̶�λ�� 
//	printf("%c\n",*++p);	//s[1]���׵�ַ ��Ԫ��  
//	printf("%c\n",*p++);	//s[1]���׵�ַ ��Ԫ��  

	p1 = p+2;
	printf("%c\n",*p1);	//
	printf("%d\n",p1);	//
//	printf("%c",*p);
//	p = p+1;
//		printf("%c",*p);

		
} 
