#include <bits/stdc++.h>
#include "tips.hpp"
using namespace std;
#define X first
#define Y second
#define MOD 1000000007
#define forn(i,n) for(int i =0;i<n;i++)
#define eprint(...) fprintf(stderr,__VA_ARGS__),fflush(stderr) 
#define mp make_pair
#define pb push_back
#define TASK "longestcommonsubsequence"
int main() {
    #ifdef home
        assert(freopen(TASK".in","r",stdin));
        //assert(freopen(TASK".out","w",stdout));
    #endif 
	string s,d;
	cin>>s>>d;
	vector<vector<int>> c(static_cast<int>(s.size()+1),vector<int>(static_cast<int>(d.size()+1)));
	for(int i =0;i<=s.size();i++){
		for(int j=0;j<=d.size();j++){
			if(i==0 || j==0) c[i][j]=0;
			else {
				if(s[i]==d[j]){
				    c[i][j]=c[i-1][j-1]+1;
				}else{
					c[i][j]=max(c[i-1][j],c[i][j-1]);
				}
			}
		}
	}
	for(int i =0;i<=s.size();i++){
		for(int j=0;j<=d.size();j++){
			cout<<c[i][j]<<" "; 
		}cout<<endl;
	}
    return 0;
}