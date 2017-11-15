#include <stdio.h>
#include <limits.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int R,C;
int min(int x, int y, int z);
int minCost(vector <vector <int>> &cost, int m, int n)
{
     int i, j;
     vector <vector <int>> tc (m+1,vector<int>(n+1));
     tc[0][0]=cost[0][0];
     for (i = 1; i <= m; i++)
        tc[i][0] = tc[i-1][0] + cost[i][0];
     for (j = 1; j <= n; j++)
        tc[0][j] = tc[0][j-1] + cost[0][j];
      for (j = 1; j < n; j++)
        tc[j][j] = 0x7FFF;
      cout<<endl<<"tc is"<<endl;
     for (i = 1; i <= m; i++){
        for (j = i+1; j <= n; j++){
          
          if(i==j){
            
            continue;
          }

          tc[i][j] = min(tc[i-1][j], 
                           tc[i][j-1]) + cost[i][j];
         
 }
     }
      for (i = 0; i <= m; i++){
        for (j = 0; j <= n; j++){
          cout<<tc[i][j]<<" ";
        }
     cout<<endl;
     }
     
     return tc[m][n];
}
int min(int x, int y, int z)
{
   if (x < y)
      return (x < z)? x : z;
   else
      return (y < z)? y : z;
}
int main()
{
vector <vector <int>> cost(200,vector<int>(200));
int n;
scanf("%d",&n);
for (int i = 0; i < n; ++i)
{
  int temp;
  scanf("%d",&temp);
  R=temp;C=temp;
  for(int i=0;i<R;i++){
    for (int j = 0; j < C; ++j)
    {
      scanf("%d",&cost[i][j]);
    }
  }

  printf("%d\n", minCost(cost, R-1, C-1));
  for (int i = 0; i < R-1; ++i)
  {
    for (int j = 0; j < C-i-1; ++j)
    {
      cost[i][j]=cost[R-j-1][R-i-1]+cost[i][j];
      cost[R-j-1][R-i-1]=cost[i][j]-cost[R-j-1][R-i-1];
      cost[i][j]=cost[i][j]-cost[R-j-1][R-i-1];      
    }
  }
   for (int i = 0; i < R; ++i)
  {
    for (int j = 0; j < R; ++j)
    {
      cout<<cost[i][j]<<" ";    
    }
    cout<<endl;
  }
  printf("%d\n", minCost(cost, R-1, R-1));
}
   
   return 0;
}