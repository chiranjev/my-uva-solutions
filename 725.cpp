#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

bool checkDifferentDigit(int a,int f,bool isZeroa,bool isZerof)
{
	int arr[10]={0};
	if(isZeroa||isZerof)
	{
		arr[0]++;
	}
	while(a>0)
	{
		arr[a%10]++;
		a/=10;
	}
	while(f>0)
	{
		arr[f%10]++;
		f/=10;
	}
	for(int i=0;i<10;i++)
	{
		if(arr[i]==0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int n,f,a;
	cin >> n;
	int ans=0;
	while(n!=0)
	{
		ans=0;
		for(f=1234;f<=49876;f++)
		{
			bool isZeroa=false;
			bool isZerof=false;
			a=f*n;
			if(a>=100000)
			{
				break;
			}
			if(a<10000)
			{
				isZeroa=true;
			}
			if(f<10000)
			{
				isZerof=true;
			}
			if(isZeroa==true&&isZerof==true)
				continue;
			if(checkDifferentDigit(a,f,isZeroa,isZerof))
			{
				ans++;
				if(isZeroa)
				cout << "0" << a << " / " << f << " = " << n << endl;
				else if(isZerof)
					cout << a << " / " << "0" << f << " = " << n << endl;
				else
					cout << a << " / " << f << " = " << n << endl;
			}
		}
		if(ans==0)
		{
			cout << "There are no solutions for " << n << "." << endl;
		}

		cin >> n;
		if(n==0)
			break;
		cout << endl;

	}


	return 0;
}
