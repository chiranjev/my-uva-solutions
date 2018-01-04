#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define MAX 101

using namespace std;

void kadane(int n,int temp[MAX],int &sum,int &len,int l,int r,int k)
{

	int startindex=0;
	int minSum,maxCount,i;
	int c=0;
	minSum=INT_MAX;
	maxCount=0;

	for(i=0;i<n;i++)
	{

		if(sum+temp[i]<=k)
		{
			sum+=temp[i];
			c=(r-l+1)*(i-startindex+1);
			
	//		cout << c << " " << sum << endl;
		}
		else
		{
			if(c>maxCount || (c==maxCount && sum<=minSum))
			{
				maxCount=c;
				minSum=sum;
	//			cout << "maxCount minSum " << maxCount << " " << minSum << endl;
			}
			i=startindex;
			startindex++;
			sum=0;
			c=0;
		}
	}
	if(c>maxCount || (c==maxCount && sum<=minSum))
	{
		maxCount=c;
		minSum=sum;
	//	cout << "maxCount minSum " << maxCount << " " << minSum << endl;
	}
	len=maxCount;
	sum=minSum;
	
//	cout << "len sum " << len << " " << sum << endl;
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
	int m,k,i,j;
	int n,l,r,sum,len;
	int cs,maxlen,minSum;

	cin >> t;

	cs=0;

	while(t--)
	{
		cin >> n >> m >> k;
		
		int arr[MAX][MAX];

		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				cin >> arr[i][j];
		maxlen=0;
		minSum=INT_MAX;

		for(l=0;l<m;l++)
		{
			int temp[MAX]={0};
			for(r=l;r<m;r++)
			{
				for(i=0;i<n;i++)
					temp[i]+=arr[i][r];
				sum=0;
				len=0;
                // for(i=0;i<n;i++)
                //     cout << temp[i] << " ";
                // cout << endl;
				kadane(n,temp,sum,len,l,r,k);

				if(len>maxlen ||(len==maxlen && sum<=minSum))
				{
					minSum=sum;
					maxlen=len;
					
//					cout << "maxlen minsum " << maxlen << " " << minSum << endl;
				}
			}
		}

		cout << "Case #" << ++cs << ": " <<  maxlen << " " << minSum << endl;
	}


	return 0;
}