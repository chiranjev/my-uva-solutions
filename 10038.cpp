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

	int i,n;
	int flag;

    while(cin >> n)
    {
    	flag=1;
    	int arr[n];
	    int darr[n-1];
	    for(i=0;i<n;i++)
	    	cin >> arr[i];
	    for(i=0;i<n-1;i++)
	    	darr[i]=abs(arr[i+1]-arr[i]);
	    sort(darr,darr+n-1);

	    for(i=0;i<n-1;i++)
	    	if(darr[i]!=i+1)
	    	{
	    		cout << "Not jolly" << endl;
	    		flag=0;
	    		break;
	    	}
		if(flag==1)
		    cout << "Jolly" << endl;
	}
	return 0;
}