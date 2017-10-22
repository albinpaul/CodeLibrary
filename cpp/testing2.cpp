#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
long int MOD = (1000000007);
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long int n,l;
    vector<long long int> s;
    //stack<int> st;
    cin>>n;
    for(l=0;n!=0;l++){
        long long int tmp=n%10;
        //st.push(tmp);
        s.push_back(tmp);
        n=n/10;
    }
    reverse(s.begin(),s.end());
    long long int res = 0;
    long long int f = 1;
    for(long long int i = l-1; i >= 0; i--) {
        res = (res + (((s[i])*f)% MOD)*(i+1)) % MOD;
        //cout<<res<<" "<<f<<endl<<endl;
        f = (f*10+1)%MOD;
        //cout<<res<<" "<<f<<endl;
    }
    long long int t=(res)%MOD;
    cout<<t;
    return 0;
}
