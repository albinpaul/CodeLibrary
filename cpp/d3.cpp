#include <bits/stdc++.h>

using namespace std;
#define TASK "d3"
int surfaceArea(vector < vector<int> > a) {
    int s=0,n=a.size();
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a.size();j++){
            if(j-1>=0){
                if(a[i][j]>a[i][j-1]){
                    s+=a[i][j]-a[i][j-1];
                }   
            }else{
               s+=a[i][j];     
            }
            if(i-1>=0){
                if(a[i][j]>a[i-1][j]){
                    s+=a[i][j]-a[i-1][j];
                }   
            }else{
               s+=a[i][j];     
            }
            
            if(i+1<=n-1){
                if(a[i][j]>a[i+1][j]){
                    s+=a[i][j]-a[i+1][j];
                }   
            }else{
               s+=a[i][j];     
            }
            if(j+1<=n-1){
                if(a[i][j]>a[i][j+1]){
                    s+=a[i][j]-a[i][j+1];
                }   
            }else{
               s+=a[i][j];     
            }
            s+=1;
        }
    }
    s+=a.size()*a.size();
    return s;
}

int main() {
     #ifdef home
        assert(freopen(TASK".in","r",stdin));
        //assert(freopen(TASK".out","w",stdout));
    #endif 
    int H;
    int W;
    cin >> H >> W;
    vector< vector<int> > A(H,vector<int>(W));
    for(int A_i = 0;A_i < H;A_i++){
       for(int A_j = 0;A_j < W;A_j++){
          cin >> A[A_i][A_j];
       }
    }
    int result = surfaceArea(A);
    cout << result << endl;
    return 0;
}
