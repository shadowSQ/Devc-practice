#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;//���Ǵ�С�����������ǴӴ�С�ĳɣ� return *(int *)b-*(int *)a;
}
int main()
{
    int a[100];
    int n;
    scanf("%d",&n);//n�����������м�������
    int i;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i-1]);
    qsort(a,n,sizeof(a[0]),cmp);//(���飬��Ҫ��������ָ���������������ռ�ڴ��С���ȽϺ�����
     for(i=1;i<=n;i++)
        printf("%d ",a[i-1]);
    return 0;
}
