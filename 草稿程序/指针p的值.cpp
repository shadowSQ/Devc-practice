#include<stdio.h>
void add(int *p)
{
    (*p)++;
    printf("%d",*p);
    if (*p>5)
    {
        return;
    }
    add(p);
}
int main()
{
    int i=0;
    add(&i);
    return 0;
}
