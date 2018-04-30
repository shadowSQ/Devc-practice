#include<stdio.h> 
int main(){
   int i=-2147483648;
   return printf("%d,%d,%d,%d",~i,-i,1-i,-1-i);
}
