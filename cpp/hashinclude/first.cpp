
#include <iostream>
 using namespace std;
int main(int argc, char const *argv[])
{
	long long int j,k,i,l;
	string s;
	cin>>s;
	 l=s.length();
	for ( i = 0; i <l; ++i)
	{
		/* code */
		for ( j = l-2-i; j >=0; --j)
		{
			cout<<".";
		}
		for ( k = 0; k <=i; ++k)
		{
			cout<<s[k];
		}
		for ( k = i-1; k>=0; k--)
		{
			/* code */
			if(k>=0)
			cout<<s[k];
		}
		cout<<"\n";
	}
	for ( i = 0; i<l-1; i++)
	{
		/* code */
		for (j = 0;j<i+1; ++j)
		{
			cout<<".";
		}

		for (k = l-1; k>i; --k)
		{
			cout<<s[k];
		}
		for (k = i+2; k<=l-1; k++)
		{
			/* code */
			
			cout<<s[k];
		}
		cout<<"\n";
	}

	return 0;
}