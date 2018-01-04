#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define MAX 210
using namespace std;

int n,q,d,m;
int arr[MAX];
int dp[201][11][201];

ll sol(int index,int c,int sum)
{
	if(c==m&&sum==0)
		return 1;
	if(c==m&&sum!=0)
		return 0;
	if(index==n)
		return 0;
	if(dp[index][c][sum]!=-1)
		return dp[index][c][sum];
	else
		dp[index][c][sum]=sol(index+1,c,sum)+sol(index+1,c+1,(sum+arr[index])%d);
	return dp[index][c][sum];
}

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int t;
	ll res;
	int i;
	int j=1;

	cin >> n >> q;
	while(n!=0&&q!=0)
	{
	    cout << "SET " << j++ << ":" << endl;
		for(i=0;i<n;i++)
			cin >> arr[i];
		for(i=0;i<q;i++)
		{
			cin >> d >> m;
			memset(dp,-1,sizeof(dp));

			res=sol(0,0,0);

			cout << "QUERY " << i+1 << ": " << res << endl;
		}
		
		cin >> n >> q;
	}


	return 0;
}