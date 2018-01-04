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
	int i,n,ans;
	int j;

	cin >> t;

	while(t--)
	{
		cin >> n;
		int arr[n];
		int ma[n];
		int mb[n];
		for(i=0;i<n;i++)
			cin >> arr[i];

		for(i=n-1;i>=0;i--)
		{
			ma[i]=1;
			mb[i]=1;
			for(j=i+1;j<n;j++)
			{
				if(arr[i]<arr[j])
				{
					ma[i]=max(ma[i],ma[j]+1);
				}

				if(arr[i]>arr[j])
					mb[i]=max(mb[i],mb[j]+1);
			}
		}

		ans=0;

		for(i=0;i<n;i++)
			ans=max(ans,ma[i]+mb[i]-1);

		cout << ans << endl;
	}


	return 0;
}














/*

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
	int ans;
	int i;
	int j;

	cin >> t;

	while(t--)
	{
		ans=0;
		cin >> n;
		int arr[n];
		int ma[n],mb[n];
		for(i=0;i<n;i++)
			cin >> arr[i];

		for(i=n-1;i>=0;i--)
		{
			ma[i]=1;
			for(j=i+1;j<n;j++)
			{
				if(arr[i]<arr[j])
					ma[i]=max(ma[j]+1,ma[i]);
			}
		}
		for(i=n-1;i>=0;i--)
		{
			mb[i]=1;
			for(j=i+1;j<n;j++)
				if(arr[i]>arr[j])
					mb[i]=max(mb[j]+1,mb[i]);
		}
		
		for(i=0;i<n;i++)
			ans=max(ans,ma[i]+mb[i]-1);

		cout << ans << endl;
	}


	return 0;
}

*/