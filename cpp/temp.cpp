#include <bits/stdc++.h>
#include "tips.hpp"
using namespace std;
int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	vector<int> v;
	v.assign(istream_iterator<int>(cin),istream_iterator<int>());
	tips::print(v);
	//replace_if(v.begin(),v.end(),bind2nd(less<int>(),2),19);
	//int as=count_if(v.begin(),v.end(),bind2nd(greater<int>(),5));
	//cout<<as<<endl;
	partial_sum(v.begin(),v.end(),v.begin());
	tips::print(v);
	return 0;
}