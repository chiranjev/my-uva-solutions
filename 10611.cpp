#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

ll upperbs(ll arr[],ll n,ll h)
{
	ll s=0,e=n-1;
	ll ans=-1;
	while(s<=e)
	{
		ll mid=(s+e)/2;

		if(arr[mid]>h)
		{
			ans=arr[mid];
			e=mid-1;
		}
		else if(arr[mid]<=h)
		{
			s=mid+1;
		}
	}
	return ans;
}

ll lowerbs(ll arr[],ll n,ll h)
{
	ll s=0,e=n-1;
	ll ans=-1;
	while(s<=e)
	{
		ll mid=(s+e)/2;

		if(arr[mid]<h)
		{
			ans=arr[mid];
			s=mid+1;
		}
		else if(arr[mid]>=h)
		{
			e=mid-1;
		}
	}
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	ll q,i,j,k,h,len,n,sum,count;
	string str;
	int t;

	cin >> n;
	ll arr[n];
	for(i=0;i<n;i++)
		cin >> arr[i];

	cin >> q;

	for(i=0;i<q;i++)
	{
		cin >> h;
		ll lower=lowerbs(arr,n,h);
		if(lower==-1)
		 	cout << "X ";
		else
			cout << lower << " ";
		ll upper=upperbs(arr,n,h);
		if(upper==-1)
		 	cout << "X" << endl;
		else
			cout << upper << endl;

	}


	return 0;
}
