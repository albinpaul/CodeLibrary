#include <list>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
 using namespace std;
 int main(int argc, char const *argv[])
 {
 	
 	int n,m,t,i,j;
 	int tmp;
 	vector<int> v;
 	vector<int> carray;
 	  std::vector<int>::iterator it;
 	cin>>t;
 	for (i = 0; i < t; ++i)
 	{
 		cin>>n>>m;
 		for (j = 0; j < m; j++)
 		{
 			cin>>tmp;
 			v.push_back(tmp);
 		}
 		sort(v.begin(),v.end());
 		int count=0;
 		int g=v.size()-1;
 		for (j=v.size()-1;j>=0;j--)
 		{
 			
 			while(v[g]>n){
 				
 				g--;
 				if(g<0)
 					break;
 			}
 			if(g!=-1){
 				//cout<<"the count is "<<<<endl;
 				n-=v[g];
 				count++;
 			}else{

 				break;
 			}
 		}
 		v.clear();
 		carray.push_back(count);

 	}
 	for(int i=0;i<carray.size();i++){
 		if(carray[i]%2!=0){
 			cout<<"Peter\n";
 		}else{
 			cout<<"Jack\n";
 		}
 	}
 	return 0;
 }