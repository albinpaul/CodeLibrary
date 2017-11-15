#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MOD 1000000007
#define TASK "ter"
typedef vector < pair <pair<int,int>,int>> vv;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
     #ifdef home
        assert(freopen(TASK".in","r",stdin));
        //assert(freopen(TASK".out","w",stdout));
    #endif 
    int n;ss
    cin>>n;
    vector<int> a(n),b(n),c(n);
    vector<int> s(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        s[i]=a[i];
    }
      for(int i=0;i<n;i++){
        cin>>b[i];
    }
       for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<n;i++){
        cout<<"for left"<<endl;
        vv d; 
        for(int j=i-1;j>=0;j--){
            cout<<s[i]<<" c[j] "<<c[i]<<" j "<<j<<" i "<<i<<endl;
            if(c[j]+j<i && i-b[i]>j){
                //scanline algorithm
                d.push_back(make_pair(make_pair(j-b[j],j+c[j]),j));               
            }
        }
        sort(d.begin(),d.end());
        int ft = d[0].X.X;
        int st= d[0].X.Y;
        int index=d[0].Y;
        s+=a[index]
        cout<<" ft "<<ft<<" st "<<st<<" index "<<index<<endl;
        for(int j=1;j<d.size();j++){
            int tempft = d[j].X.X;
            int tempst= d[j].X.Y;
            int tempindex=d[j].Y;int flag=1;
            cout<<" tempft "<<tempft<<" tempst "<<tempst<<" tempindex "<<tempindex<<endl;
            if(st>=tempft && ){
                flag=0;
                s-=a[index];
            }
            while(st>=tempft){

            }
            if (flag==1){
                s+=a[tempindex];
                index=tempindex;
                ft=tempft;
                st=tempst;            
            }
        }
        d.clear();
        cout<<"for right"<<endl;
        for(int j=i+1;j<n;j++){
            cout<<s[i]<<" b[j] "<<b[j]<<" j "<<j<<" i "<<i<<endl;
            if(j-b[j]>i && c[i]+i<j){
                d.push_back(make_pair(make_pair(j-b[j],j+c[j]),j)); 
                s[i]+=a[j];
            }
            cout<<"s[i] "<<s[i]<<endl;
        }
        sort(d.begin(),d.end());
        for(int j=0;j<d.size();j++){
            int ft = d[j].X.X;
            int st= d[j].X.Y;
            int index=d[j].Y;
            cout<<" ft "<<ft<<" st "<<st<<" index "<<index<<endl;
        }
        d.clear();
    }
    for(int i =0;i<n;i++) {
        cout<<s[i]<<" ";
    }
    cout<<endl;
    return 0;
}
