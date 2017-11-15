#include <bits/stdc++.h>
#include "tips.hpp"
using namespace std;
#define X first
#define Y second
#define MOD 1000000007
#define forn(i,n) for(int i =0;i<n;i++)
#define mp make_pair
#define pb push_back
#define TASK "stringtonumber"
template <class T>
T string_number(const string &s){
	stringstream g(s);
	T num;
	g>>num;
	return num;
} 
int main() {
    #ifdef home
        assert(freopen(TASK".in","r",stdin));
        //assert(freopen(TASK".out","w",stdout));
    #endif 

	int i= string_number<int>("56");
	double d= string_number<double>("56.5");
	cout<<i<<" "<<d<<endl;
    return 0;
}