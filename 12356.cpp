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

	int s,b,i;
	int l,r;

	cin >> s >> b;

	while(b!=0&&s!=0)
	{
		int pre[s+1];
		int suff[s+1];
		for(i=0;i<s+1;i++)
		{
			pre[i]=i-1;
			suff[i]=i+1;
		}
		for(i=0;i<b;i++)
		{
			cin >> l >> r;
			if(pre[l]==0)
				cout << "* ";
			else
				cout << pre[l] << " ";
			if(suff[r]>s)
				cout << "*";
			else
				cout << suff[r];
			cout << endl;
			pre[suff[r]]=pre[l];
			suff[pre[l]]=suff[r];
		}
		cout << "-" << endl;
		cin >> s >> b;
	}


	return 0;
}