#include <bits/stdc++.h>

using namespace std;
#define TASK "triple"
void tripleRecursion(int n, int m, int k) {
    vector<vector<int>> v(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
    	for (int j = 0; j < n; ++j)
    	{
    		if(j==0 && i==0) {
    			v[i][j]=m;
    		}else if(i==j){
    			v[i][j]=v[i-1][j-1]+k;
    		}else if(i>j){
    			v[i][j]=v[i-1][j]-1;
    		}else if(i<j){
    			v[i][j]=v[i][j-1]-1;
    		}
    	}
    }
    for(int i =0;i<n;i++){
    	for (int j= 0; j < n; ++j)
    	{
    		cout<<v[i][j]<<" ";
    	}cout<<endl;
    }
}

int main() {
	   #ifdef home
        assert(freopen(TASK".in","r",stdin));
        //assert(freopen(TASK".out","w",stdout));
    #endif 
    int n;
    int m;
    int k;
    cin >> n >> m >> k;
    tripleRecursion(n, m, k);
    return 0;
}
