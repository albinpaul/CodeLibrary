#include <list>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 using namespace std;

 int main(int argc, char const *argv[])
 {
 	int T;
 	long long N,M,tmp;
 	std::vector<int> v;
 	cin>>T;
 	for(int i =0;i<T;i++){
 		cin>>N>>M;
 		int count=0;
 		priority_queue <long> gquiz;
		for (int j = 0; j < M; ++j)
		{
			cin>>tmp;
			gquiz.push(tmp);
		}
		for (int j = 0; j < M; ++j)
		{
			if(gquiz.top()<=N){
				count++;
				N-=gquiz.top();
				
			}
			gquiz.pop();
		}

		
 		v.push_back(count);
 	}
 	for(int i =0;i<v.size();i++){
 		if(v[i]%2==0){
 			cout<<"Jack\n";	
 		}else{
 			
 			cout<<"Peter\n";
 		}
 	}
 	return 0;
 }