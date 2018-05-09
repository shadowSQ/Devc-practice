#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
  
  
void kmpMatch(char * s,int sLength,char * p,int pLength,int *prefix)  
{  
    int pPoint=0;  
    for(int i=0; i<=sLength-pLength;i++)  
    {  
  
  
        while(pPoint!=0&&(s[i]!=p[pPoint]))  
        {  
            pPoint = prefix[pPoint-1];  
        }  
        if(s[i]==p[pPoint])  
        {  
            pPoint++;  
            if(pPoint == pLength)  
            {  
                printf("�ҵ�:%d \n",i-pPoint+1);  
                //pPoint = 0;//��һ����sƥ����ַ���,���ܳ�Ϊ��һ��ƥ���ַ�����һ����  
                pPoint=prefix[pPoint-1];//��һ����sƥ����ַ���,Ҳ�ܳ�Ϊ��һ��ƥ���ַ�����һ����  
            }  
        }  
  
  
    }  
}  
  
void kmpPrefixFunction(char *p,int length,int *prefix)  
{  
    prefix[0]=0;  
    int k = 0;//ǰ׺�ĳ���  
    for(int i=1; i<length; i++)  
    {  
        while(k>0&&p[k]!=p[i])  
        {  
            k=prefix[k-1];  
        }  
        if(p[k]==p[i])//˵��p[0...k-1]��k����ƥ����  
        {  
            k=k+1;  
        }  
        prefix[i]=k;  
    }  
}  
  
  
//ƥ�亯���������㷨,���ڱȽ�  
void normal_match(char * s,int sLength,char * p,int pLength){  
    int k;  
    for(int i=0;i<sLength-pLength+1;i++){  
        for(k=0;k<pLength;k++){  
            if(s[i+k]!=p[k]){  
                break;  
            }  
        }  
        if(k==pLength){  
            printf("�ҵ�:%d \n",i);  
        }  
  
    }  
}  
  
  
int main()  
{  
    char *s = "ababacababababababbaabbababaabaababacabababababbcababbabababcababba";  
    char *p = "ababacab";  
    int pLength = strlen(p);  
    int *prefix = (int *)malloc(pLength*sizeof(int));  
    kmpPrefixFunction(p,pLength,prefix);  
    printf("�ַ������ǰ׺���ȷֱ���:");  
    for(int i=0; i<pLength; i++)  
    {  
        printf("%d\t",prefix[i]);  
    }  
    printf("\nʹ��KMPƥ��\n");  
    kmpMatch(s,strlen(s),p,pLength,prefix);  
  
    printf("ʹ�������㷨:\n");  
    normal_match(s,strlen(s),p,pLength);  
  
    return 0;  
}  
