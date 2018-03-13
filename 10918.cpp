#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	ll i,j,k,len,n,sum,count;
	string str;

	ll f[31];
	ll g[31];

	f[0]=1;
	f[1]=0;
	g[0]=0;
	g[1]=1;

	for(i=2;i<31;i++)
	{
		f[i]=f[i-2]+2*g[i-1];
		g[i]=f[i-1]+g[i-2];
	}

	cin >> n;

	while(n!=-1)
	{
		cout << f[n] << endl;

		cin >> n;
	}


	return 0;
}
