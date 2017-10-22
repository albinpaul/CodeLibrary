#include <bits/stdc++.h>
#include <vector>

using namespace std;
typedef vector<vector<int>> vv;
int n,x,y;
void diverse(vv &v,int w){
  
     for(int g=x-w+1,i=1;g<x+w;g++,i++){
         for(int j=1, h=y-w+1;h<y+w;h++,j++){
           // cout<<i<<" "<<j<<" "<<2*w-i<<" "<<2*w-j<<" "<<w<<endl;
            if(0<=g && 0<=h && g<n && h<n)
                v[g][h]+=min(min(min(i,j),2*w-i),2*w-j); 
        }
     } 
                
}
int main() {
    cin >> n;
    int m;
    cin >> m;
    vv v(n,vector<int>(n,0));
  
    for(int a0 = 0; a0 < m; a0++){
        
        int w;
        cin >> x >> y >> w;
        // Write Your Code Here
        diverse(v,w);
       
    }
    long int max=0;
    for(int g=0;g<n;g++){
        for (int h = 0; h < n; ++h)
        {

            if(max<v[g][h]){
                max=v[g][h];
            }
            
        }
       
     } 
    cout<<max;   
    return 0;
}
