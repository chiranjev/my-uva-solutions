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

	int t;
	int n;
	int i,j;
	int c=1;
	int maxli,maxld;
	cin >> t;

	while(t--)
	{
		cin >> n;
		int h[n];
		int w[n];
		int li[n];
		int ld[n];

		for(i=0;i<n;i++)
			cin >> h[i];
		for(i=0;i<n;i++)
			cin >> w[i];
		
		for(i=0;i<n;i++)
		{
			li[i]=w[i];
			ld[i]=w[i];
			for(j=0;j<i;j++)
			{
				if(h[i]>h[j])
					li[i]=max(li[i],li[j]+w[i]);
				if(h[i]<h[j])
					ld[i]=max(ld[i],ld[j]+w[i]);
			}
		}

		maxli=0;
		maxld=0;
		for(i=0;i<n;i++)
		{
			maxli=max(maxli,li[i]);
			maxld=max(maxld,ld[i]);
		}
		if(maxli>=maxld)
			cout << "Case " << c++ << ". Increasing (" << maxli << "). Decreasing (" << maxld << ")." << endl;
		else
			cout << "Case " << c++ << ". Decreasing (" << maxld << "). Increasing (" << maxli << ")." << endl;
	}


	return 0;
}