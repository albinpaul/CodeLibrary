#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
long long int calc(long long int  a ,long long int b){
    if(b>0){
        return ((a*(a+1))/2)-((b-1)*(b))/2;
    }else{
        return a*(a+1)/2;
    }
}
int main() {
    /* keep calm and do your shit */ 
    long  n,k,j,s=0,t=0;
    cin>>n>>k;
    vector<vector<long long int>> a(k,vector<long long int>(2));
    for(long long int i =0;i<k;i++){
        long long int l,r;
        cin>>l>>r;
        a[i][0]=l;
        a[i][1]=r;
    }
    sort(a.begin(),a.end());
    stack<pair<long long int,long long int>> st;
    /*for(long long int i =0;i<k;i++){
       cout<<a[i][0]<<" "<<a[i][1]<<endl;
    }*/
   
    s+=calc(a[0][1],a[0][0]);

    cout<<"return of calc function "<<s<<endl; 
    //extra left
    if(a[0][0]>0){
     s+=a[0][0]-1;
         
        if(a[0][0]-1>0){
            st.push(make_pair(0,a[0][0]-1-1));
            cout<<"pair pushed  "<<0<<" "<<a[0][0]-1-1<<endl;
        }
          cout<<" added element "<<a[0][0]-1<<endl;  
    }
    //extra right
    if(a[0][1]<n-1){
        cout<<"added element "<<a[0][1]+1<<endl;
        s+=a[0][1]+1;
        if(a[0][1]+1==n-1){
            t=-1;
        }else{
            t=a[0][1]+2;
        }
    }
    cout<<s<<endl;
    for (long long int i = 1; i < k; ++i)
    {

        s=calc(a[i][1],a[i][0]);
        cout<<"return of calc function "<<s<<" t "<<t <<endl; 
        if(t!=-1 ){
            if(t<a[i][0]){
            st.push(make_pair(t,a[i][0]-1));
            cout<<"pair pushed "<<t<<" "<<a[i][0]-1<<endl;
            }
        }
        //for left part
        if(st.empty()==0){
            if(st.top().second==st.top().first){
                 cout<<"element popped "<<st.top().second<<endl;
                s+=st.top().second;
                st.pop();
            }else{
                cout<<"element "<<st.top().second<<endl;
                s+=st.top().second;
                st.top().second-=1;

            }
        }
        //for right part
        if(a[i][1]<n-1){
            cout<<"added extra element  "<<a[i][1]+1<<endl;
            s+=a[i][1]+1;
            t=a[i][i]+2;
        }else{
            t=-1;
        }
        cout<<s<<endl;       
    }
      
    return 0;
}
