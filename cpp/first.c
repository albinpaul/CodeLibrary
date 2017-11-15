#include <stdio.h>
void main(){
    int n = 0;
    scanf("%d",&n);
    int a[n];
    printf("Number of elements in array is %lu\n",sizeof(a)/sizeof(int));
}