#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MOD 1000000007
#define forn(i,n) for(int i =0;i<n;i++)
#define mp make_pair
#define pb push_back
typedef long long ll;
const double PI=3.141592;
const int inf =(int) 1.01e9;
const double eps =(1e-9);
#define TASK "segmentt"
using namespace std;
#define ll long long
const int N = 5e5+10;
ll tree[4*N];
int L[N],R[N],S[N],P[N];
vector<int> indices[N];
ll dp[N],dp2[N];
void update(int i, int j, int l, ll val, int ind)
{
 	if(l < i || l > j)
   		return;
   	if(i == j){
   		tree[ind] = val;
   		return;
   	}
   	int mid = (i+j)/2;
   	update(i,mid,l,val,2*ind);
   	update(mid+1,j,l,val,2*ind+1);
   	tree[ind] = max(tree[2*ind+1],tree[2*ind]);
}
ll query(int i, int j, int l, int r, int ind)
{
   	if(l > j || i > r)
   		return 0;
   	if(i >= l && j <= r)
   		return tree[ind];
   	int mid = (i+j)/2;
   	return max(query(i,mid,l,r,2*ind),query(mid+1,j,l,r,2*ind+1));
}
int main()
{ 
    #ifdef home
        assert(freopen(TASK".in","r",stdin));
        //assert(freopen(TASK".out","w",stdout));
    #endif 
   	int n;
   	cin>>n;
   	for(int i = 1;i<=n;i++)
   		cin>>S[i];
   	for(int i = 1;i<=n;i++)
   		cin>>L[i];
   	for(int i = 1;i<=n;i++){
   		cin>>R[i];
   		if(i+R[i] < n)
   			indices[i+R[i]+1].emplace_back(i);
   	}
   	for(int i = 1;i<=n;i++)
   	{
   		for(int j:indices[i])
   			update(1,n,j,dp2[j],1);
   		int li = i-L[i]-1;
   		dp2[i] = (li<1?0:query(1,n,1,li,1))+S[i];
   		dp[i] = max(dp[i-1],dp2[i]);
   	}
   	cout<<dp[n];
}