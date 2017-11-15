#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
 
using namespace std;
const long inf =(long) 1.01e9;
long long factorial(long long n)
{
    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;
}
long long gcd(long a , long b){
    if(b%a==0)return a;
    return gcd(b%a,a);
}
long sum(long freq[], long i, long j)
{
    long s = 0;
    for (long k = i; k <=j; k++)
       s += freq[k];
    return s;
}
long optimalSearchTree(long long freq[], long n)
{
    /* Create an auxiliary 2D matrix to store results 
      of subproblems */
    long cost[n+1][n+1]={0};
    for (long i = 0; i < n; i++)
        cost[i][i] = freq[i];
    for (long L=2; L<=n; L++)
    {
        // i is row number in cost[][]
        for (long i=0; i<=n-L+1; i++)
        {    long j = i+L-1;
            if(L==2){
                 cost[i][j] = cost[i][j-1]+cost[i+1][j];
            }else{
                cost[i][j] = (cost[i][j-1]+cost[i+1][j])*2;
            }
           
          
        }
    }
    //for(long i =0;i<n;i++) {for(long j=0;j<n;j++){cout<<" "<<cost[i][j];}cout<<endl;} 
    return cost[0][n-1];
}

int main() {
    /* Enter your code here. Read input from STDIN. Prlong output to STDOUT */ 
    long long n;
    cin>>n;
    for(long i =0;i<n;i++){
        long long t=0;
        
        cin>>t;
       long long v[t];
        for (long long j=0;j<t;j++){
            cin>>v[j];
        }
        sort(v,v+t);
        long long sum=optimalSearchTree(v,t);
        long long f=factorial(t);
        //cout<<" t factorial "<<f<<endl;
        long long g=gcd(sum,f);
        //cout<<"g "<<g<<endl;
        if(sum % f==0){
            cout<<sum/f<<endl;
        }else{
            cout<<sum/g<<"/"<<f/g<<endl;
        }
        //cout<<sum<<endl;
    }
    return 0;
}
