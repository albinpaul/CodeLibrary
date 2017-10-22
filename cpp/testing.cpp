#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std; // }}}

int main()
{ 
    int N, I;
    cin >> N >> I;
    vector<vector<int> > pairs(N);
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }
 
    long long result = 0;
    long long sum = 0;
    vector <long long > leng;
    /** Write code to compute the result using N,I,pairs **/
    stack <int> S;
    vector <int> visited(N);
    for(int i=0;i<N;i++){
        if(visited[i]==0){
            long long count=0;
            visited[i]=1;
            count++;
            for(int j=0;j<pairs[i].size();j++){
                cout<<"pairs are"<<pairs[i][j]<<" "<<endl;
                S.push(pairs[i][j]);
            }
            while(!S.empty()){
                long int ele=S.top();
                count++;
                visited[ele]=1;
                S.pop();
                for(int k=0;k<pairs[ele].size();k++)
                {
	                    if (visited[k]==0){
	                        S.push(pairs[ele][k]);
	                    }
                }
            }
            leng.push_back(count);
           	cout<<" count "<<count<<endl;
           	

        }
    }
    result=leng[0]*leng[1];
    sum=leng[0]+leng[1];
    for(int i=2;leng[i]!='\0';i++){
    	
    	result+=sum*leng[i];
    	sum+=leng[i];
    }   
    
        
    cout << result << endl;
    return 0;
}
