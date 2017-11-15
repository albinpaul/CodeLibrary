#include <bits/stdc++.h>
using namespace std;
#define TASK "segmenttree"
typedef long long                LL;
#define N                        500100
#define LOGN                     23
#define SI(n)                    scanf("%d",&n)
#define PLLN(n)                  printf("%lld\n",n)
#define REP(i,j,n)               for(LL i=j;i<n;i++)

LL pst[N*LOGN] , root[N] , L[N*LOGN] , R[N*LOGN];
LL ptr;
int power[N] , lft[N] , rght[N];

void make_tree(int l , int h , int root) {
  pst[root] = 0;
  if(l == h)
    return;
  L[root] = ptr ++;
  R[root] = ptr ++;
  int mid = (l + h)/2 , c1 = L[root] , c2 = R[root];
  make_tree(l , mid , c1);
  make_tree(mid+1 , h , c2);
}

LL update_tree(int pos , LL x , int l , int h , int root) {
  int newRoot = ptr ++;
  pst[newRoot] = pst[root];
  if(l == h) {
    pst[newRoot] = max(pst[newRoot] , x);
    return newRoot;
  }
  L[newRoot] = L[root] , R[newRoot] = R[root];
  int mid = (l + h)/2 , c1 = L[newRoot] , c2 = R[newRoot];
  if(pos <= mid)
    L[newRoot] = update_tree(pos , x , l , mid , L[newRoot]);
  else
    R[newRoot] = update_tree(pos , x , mid+1 , h , R[newRoot]);
  pst[newRoot] = max(pst[L[newRoot]] , pst[R[newRoot]]);
  return newRoot;
}

LL query(int ql , int qh , int l , int h , int root) {
  if(ql > h || qh < l || l > h) return 0;
  if(ql <= l && h <= qh) {
    return pst[root];
  }
  int mid = l + h >> 1 , c1 = L[root] , c2 = R[root];
  LL q1 = query(ql , qh , l , mid , c1);
  LL q2 = query(ql , qh , mid+1 , h , c2);
  return max(q1 , q2);
}

int main() {
   #ifdef home
        assert(freopen(TASK".in","r",stdin));
        //assert(freopen(TASK".out","w",stdout));
    #endif 
  ptr = 0;
  int n; SI(n);
  REP(i,1,n+1) SI(power[i]);
  REP(i,1,n+1) SI(lft[i]);
  REP(i,1,n+1) SI(rght[i]);
  LL ans = 0;
  make_tree(0,n+1,0);
  for(int i =0;i<n;i++){
    cout<<" L[i] "<<L[i]<<" R[i] "<<R[i]<<endl;
  }
  REP(i,1,n+1) {
    int ind = i - lft[i] - 1;
    LL val = query(0,i,0,n+1,root[ind]) + power[i];
    ans = max(val , ans);
    root[i] = update_tree(i+rght[i]+1,val,0,n+1,root[i-1]);
  }
  PLLN(ans);
  return 0;
}