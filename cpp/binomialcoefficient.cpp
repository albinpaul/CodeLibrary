#include <bits/stdc++.h>
#include "tips.hpp"
using namespace std;
#define X first
#define Y second
#define MOD 1000000007
#define forn(i,n) for(int i =0;i<n;i++)
#define mp make_pair
#define pb push_back
#define TASK "binomialcoefficient"
int main() {
    #ifdef home
        assert(freopen(TASK".in","r",stdin));
        //assert(freopen(TASK".out","w",stdout));
    #endif 
     int n,k;
     cin>>n>>k;
     vector<vector<int>> V(n+1,vector<int>(k+1));
     //int c[9][9];
     
     for(int i =1;i<=n;i++){
     	for(int j=0;j<=k;j++){
     		if(j==i || i==1 ) V[i][j]=1;
     		else {V[i][j]=V[i-1][j-1]+V[i-1][j];}  
     	}
     }   
	for(int i =0;i<=n;i++){
     	for(int j=0;j<=k;j++){
     		cout<<" "<<V[i][j];
     	}
     	cout<<endl;
     }  
    return 0;
}