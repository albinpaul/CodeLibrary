#include <bits/stdc++.h>

using namespace std;
typedef unordered_map<long long,long long int> m;
int main() {
    long long int n,mi=0x7FFFFFFF;
    cin >> n;
    vector<long long int> A(n),B(n/1000 +1,0x7FFFFFFF);
    m um;
    for(long long int A_i = 0; A_i < n; A_i++){
       cin>>A[A_i];
        m::iterator it=um.find(A[A_i]);
        if(B[A_i/1000]>A[A_i]){
            B[A_i/1000]=A[A_i];    
        }
        if(it==um.end()){
            um.insert(make_pair(A[A_i],A_i));
        }else
        {
            it->second=A_i;
        }
    }
   long long  int q;
    cin >> q;
    for(int i =0;i<A.size();i++){
        if(mi>A[i]){
            mi=A[i];
        }
    }
    for(long long int a0 = 0; a0 < q; a0++){
        long long int xi;
        cin >> xi;
         long long int result;
        if(xi<mi){
            result=-1;
        }else{
            int j;
            for(j=B.size()-1;j>=0;j--)
            {
                if(B[j]<=xi){
                    //cout<<"Bj "<<B[j]<<" "<<B.size()<<" j "<<j<<endl;
                    break;
                }
            }
            for(int i =((n-j*1000)>=1000)?(j+1)*1000-1:(n%1000)-1; i>=j*1000 ;i-- ){
              
                if(A[i]<=xi){
                    result=i+1;
                    break;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
