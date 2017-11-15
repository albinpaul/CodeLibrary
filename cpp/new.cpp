#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second
#define MOD 1000000007
#define forn(i,n) for(int i =0;i<n;i++)
#define eprint(...) fprintf(stderr,__VA_ARGS__),fflush(stderr) 
#define mp make_pair
#define pb push_back
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define ss(n) scanf("%s",n)
#define pnl printf("\n")
#define IOS ios_base::sync_with_stdio(0);
typedef long long ll;
const double PI=3.1415926535897;
const int inf =(int) 1.01e9;
const double eps =(1e-9);
#define TASK "new"
int main() {
    #ifdef home
        assert(freopen(TASK".in","r",stdin));
        //assert(freopen(TASK".out","w",stdout));
    #endif 
        long long int n;
        cin>>n;
        if(n&1L){
            cout<<"N0"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
    
    return 0;
}