#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;//这是从小到大排序，若是从大到小改成： return *(int *)b-*(int *)a;
}
int main()
{
    int a[100];
    int n;
    scanf("%d",&n);//n代表数组中有几个数字
    int i;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i-1]);
    qsort(a,n,sizeof(a[0]),cmp);//(数组，需要排序的数字个数，单个数字所占内存大小，比较函数）
     for(i=1;i<=n;i++)
        printf("%d ",a[i-1]);
    return 0;
}
