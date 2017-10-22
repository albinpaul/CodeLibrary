#include <list>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
 using namespace std;
 int main()
 {
 	long long int Number=1000000007;
 	//matrix 1 normal free matrix 2 individual matrix 3  connected
 	long long int N=10;//0;//001;
 	long long int t,i,j,arr1[N][N]={0},arr2[N][N]={0},arr3[N][N]={0};
 	
 	for(i=2;i<N;i++){
 		arr1[i][2]=arr2[i][2]=arr3[i][2]=i-2+1;

 	}
 	for (i = 3; i < N; ++i)
 	{
 		arr1[i][3]=arr2[i][3]=arr3[i][3]=i-3+1;
 	}
 	for(i=4;i<N;i++){
 		for(j=4;j<=i;j++){
 			if(i-2>=j){
 				arr1[i][j]=(arr1[i][j]+arr1[i-2][j])%Number;
 				arr3[i][j]=(arr3[i][j]+arr1[i-2][j])%Number;
 			}
 			if(i-1>=j){
 				arr1[i][j]=(arr1[i][j]+arr2[i-2][j-1])%Number;
 				arr2[i][j]=(arr2[i][j]+arr1[i-2][j-1])%Number;
 				arr3[i][j]=(arr3[i][j]+arr1[i-2][j-1]+arr2[i-2][j-1])%Number;
 			}
 			if(i>=j){
 				arr1[i][j]=(arr1[i][j]+arr3[i-2][j-2])%Number;
 				arr2[i][j]=(arr2[i][j]+arr3[i-2][j-2])%Number;
 				arr3[i][j]=(arr3[i][j]+arr3[i-2][j-2])%Number;
 			}
 			//arr3[i][j]=arr1[i-2][j-1]+arr2[i-2][j-1]+arr3[i-2][j-2];	
 		}
 	}
 	
 	for (i = 2; i < N; ++i)
 	{
 		for(j=2;j<N;j++){
 			cout<<arr1[i][j]<<" ";
 		}
 		cout<<endl;
 	}
 	cout<<endl;
 		for (i = 2; i < N; ++i)
 	{
 		for(j=2;j<N;j++){
 			cout<<arr2[i][j]<<" ";
 		}
 		cout<<endl;
 	}
 	cout<<endl;
 		for (i = 2; i < N; ++i)
 	{
 		for(j=2;j<N;j++){
 			cout<<arr3[i][j]<<" ";
 		}
 		cout<<endl;
 	}
	cin>>t;
	long long int tmp1,tmp2;
	for(i=0;i<t;i++){
		cin>>tmp1>>tmp2;
		if(tmp1!=1||tmp2!=1){
			cout<<arr1[tmp1][tmp2]<<endl;
		}
		else{
			cout<<0<<endl;
		}
	}
 	return 0;
 }