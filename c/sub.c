#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
long int MOD = (1000000007);
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char c;
    int array[2000000];
    long long int size=0;
    while((c=getchar())!='\n'){
    	array[size]=c-'0';
    	size++;
    }
    /*
    for(long long int i=0;i<size;i++){
    	printf("%d %lld\n",array[i],i);
    }
    */
    long long int res = 0;
    long long int f = 1;
    for(long long int i = size-1; i >= 0; i--) {
        res = (res + ((array[i])*f)*(i+1)) % MOD;
        //cout<<res<<" "<<f<<endl<<endl;
        f = (f*10+1)%MOD;
        //cout<<res<<" "<<f<<endl;
    }
    printf("the answer is %lld\n",res);
    return 0;
}
