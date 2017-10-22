#include <bits/stdc++.h>

using namespace std;

int tileStackingProblem(int n, int m, int k) {
    // Complete this function
  vector<vector <int>> v(n+1,vector<int>(m,0));
  for(int j=0;j<m;j++){
    v[0][j]=1;
  }

  for(int i =1;i<=n;i++){
   for(int j=0;j<m;j++){
     for(int g=k;g>=0;g--){
     
      }
   }

 }
 for(int i =0;i<=n;i++){
  for(int j=0;j<m;j++){
    cout<<v[i][j]<<" ";
  }
  cout<<endl;
}
return v[n][m-1];
}

int main() {
  int n;
  int m;
  int k;
  cin >> n >> m >> k;
  int result = tileStackingProblem(n, m, k);
  cout << result << endl;
  return 0;
}
