#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

int visited[8][8];
char graph[8][8];

vector<string> result;

bool isValid(int i,int j,int m,int n)
{
	if(i<m&&i>=0&&j<n&&j>=0)
		return true;
	return false;
}



char path[7]={'I','E','H','O','V','A','#'};

void dfs(int x,int y,int m,int n,int k)
{
	if(k==8)
		return;
	if(isValid(x,y-1,m,n)&&graph[x][y-1]==path[k])
	{
		result.pb("left");
		dfs(x,y-1,m,n,k+1);
	}
	else if(isValid(x,y+1,m,n)&&graph[x][y+1]==path[k])
	{
		result.pb("right");
		dfs(x,y+1,m,n,k+1);
	}
	else if(isValid(x-1,y,m,n)&&graph[x-1][y]==path[k])
	{
		result.pb("forth");
		dfs(x-1,y,m,n,k+1);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	    // for getting input from input.txt
	    freopen("input.txt", "r", stdin);
	    // for writing output to output.txt
	    freopen("output.txt", "w", stdout);
	#endif

	int i,j,k,len,n,sum,count;
	string str;
	int m;
	int t;
	char c;

	cin >> t;

	while(t--)
	{
		cin >> m >> n;
		result.clear();

		memset(visited,0,sizeof(visited));

		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
					cin >> graph[i][j];
			}
		}
		k=0;
		for(j=0;j<n;j++)
		{
			if(graph[m-1][j]=='@')
			{
				dfs(m-1,j,m,n,k);
				break;
			}
		}
		cout << result[0];
		for(i=1;i<result.size();i++)
			cout << " " << result[i];
		cout << endl;

	}


	return 0;
}
