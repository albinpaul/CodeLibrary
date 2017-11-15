#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long long int n,k,j,s=0;
    cin>>n>>k;
    vector<pair<long long int,long long int>> a;
     long long int l,r;
    cin>>l>>r;
    for(j=l;j<=r;j++){
            s+=j;
    }
    
    if(l>0 && r< n-1){
        s+=r+1+l-1;
        a.push_back(make_pair(l-1,r+1));
    }
    else if(l==0 && r< n-1){
        s+=r+1;
        a.push_back(make_pair(0,r+1));
    } 
    if(l>0 && r==n-1){
        s+=l-1;
        a.push_back(make_pair(l-1,r));
    }
    cout<<s<<endl;
    for(long long int i =1;i<k;i++){
        cin>>l>>r;
        s=0;
        for(j=l;j<=r;j++){
            s+=j;
        }
    
        int f1=0,f2=0;
        for(int g=0;g<a.size();g++){
            if(l==a[g].second+1){
                if(a[g].first>0){
                      a[g].first-=1;
                    s+=a[g].first;
                }
                a[g].second=r;
                f1=1;
                break;
            }
            if(l==a[g].second+2){
                l-=1;
                a[g].second=r;
                f1=1;
                
                break;
            }    
        }
        for(int g=0;g<a.size();g++){
            if(r==a[g].first-1){
                if(a[g].second<n-1){
                      a[g].second+=1;
                    s+=a[g].second;
                }
                a[g].first=l;
                f2=1;
                break;
            }
            if(l==a[g].second+2){
                l-=1;
                a[g].second=r;
                f2=1;
                
                break;
            }    
        }
       if(f1==0 && l>0){
            l-=1;
           s+=l;
       }
        if(f2==0 && r<n-1){
            r+=1;
           s+=r;
       }
        cout<<s<<endl;
    }
       
    return 0;
}
