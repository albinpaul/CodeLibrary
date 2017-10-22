#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int c[100],mi=(int)0x7fffffff;
    cin>>n;
    vector<int> a;
    for(int i =0;i<n;i++){
        cin>>tmp;
        a.insert(tmp);
        
    }
    cin>>m;
    vector<int> b(m);
     for(int i =0;i<m;i++){
        cin>>tmp;
        if(tmp<mi){
            mi=tmp;
        }
        b[i]=tmp;
        
    }
    for(int i =0;i<m;i++){        
        c[b[i]-mi]++;
    }
     for(int i =0;i<n;i++){        
        c[a[i]-mi]--;
    }
    for(int i=0;i<100;i++){
        if(c[i]>0){
            while(c[i]>0) {
                cout<<c[i]+min<<" ";
            }
        }
    }    
    return 0;
}
