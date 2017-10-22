#include <list>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
 using namespace std;
 int main(int argc, char const *argv[])
 {
 	long long int Number=1000000007;
 	//matrix 1 normal free matrix 2 individual matrix 3  connected
 	long long int N,K,Num=100001;

 	long long int t,i,j,arr1[3][Num]={0},arr2[3][Num]={0},arr3[3][Num]={0},g;

	// for(i=2;i<N;i++){
 // 		arr1[i][2]=arr2[i][2]=arr3[i][2]=i-2+1;

 // 	}
 // 	for (i = 3; i < N; ++i)
 // 	{
 // 		arr1[i][3]=arr2[i][3]=arr3[i][3]=i-3+1;
 // 	}
 	long int temp=0;
 	cin>>temp;
 	for(int m=0;m<temp;m++){
 		cin>>N>>K;
 		if(N!=1 && (K>3)){
		 	for(i=4;i<=N;i++){
		 		
		 		arr1[0][2]=arr2[0][2]=arr3[0][2]=i-2-2+1;
		 		arr1[0][3]=arr2[0][3]=arr3[0][3]=i-3-2+1;
		 		for(j=4;j<=i;j++){
		 			if(i-2>=j){
		 				arr1[2][j]=(arr1[2][j]+arr1[0][j])%Number;
		 				arr3[2][j]=(arr3[2][j]+arr1[0][j])%Number;
		 			}
		 			if(i-1>=j){
		 				arr1[2][j]=(arr1[2][j]+arr2[0][j-1])%Number;
		 				arr2[2][j]=(arr2[2][j]+arr1[0][j-1])%Number;
		 				arr3[2][j]=(arr3[2][j]+arr1[0][j-1]+arr2[0][j-1])%Number;
		 			}
		 			if(i>=j){
		 				arr1[2][j]=(arr1[2][j]+arr3[2-2][j-2])%Number;
		 				arr2[2][j]=(arr2[2][j]+arr3[2-2][j-2])%Number;
		 				arr3[2][j]=(arr3[2][j]+arr3[2-2][j-2])%Number;
		 				// arr1[i][j]=(arr1[i][j]+arr3[i-2][j-2])%Number;
		 				// arr2[i][j]=(arr2[i][j]+arr3[i-2][j-2])%Number;
		 				// arr3[i][j]=(arr3[i][j]+arr3[i-2][j-2])%Number;		
		 			}

		 			//arr3[i][j]=arr1[i-2][j-1]+arr2[i-2][j-1]+arr3[i-2][j-2];	
		 		}

		 		for(g=0;g<2;g++){
		 			for(j=4;j<=K;j++){
		 				arr1[g][j]=arr1[g+1][j];
		 				arr2[g][j]=arr2[g+1][j];
		 				arr3[g][j]=arr3[g+1][j];
		 			}
		 				
		 		}
		 		
		 		for(j=4;j<=K;j++){
		 			arr1[g][j]=arr2[g][j]=arr3[g][j]=0;
		 		}
		 	}
		 	cout<<arr1[1][K]<<endl;
		 }else{
			 	if(K==2){
			 		cout<<N-2+1<<endl;
			 	}
			 	else if(K==3){
			 		cout<<N-3+1<<endl;
			 	}else{
			 	cout<<0<<endl;
			 }
		 }
 	
 	}
 	return 0;
 }