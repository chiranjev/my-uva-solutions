#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

int visited[101][101];
char graph[101][101];

bool isValid(int i,int j,int n)
{
	if(i<n&&i>=0&&j<n&&j>=0)
		return true;
	return false;
}

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

void dfs(int x,int y,int n)
{
	for(int i=0;i<4;i++)
	{
		int posx=x+dx[i];
		int posy=y+dy[i];
		if(isValid(posx,posy,n)&&!visited[posx][posy]&&(graph[posx][posy]=='x'||graph[posx][posy]=='@'))
		{
			visited[posx][posy]=1;
			dfs(posx,posy,n);
		}
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
	int ans;
	cin >> t;
	k=0;
	while(t--)
	{
		ans=0;
		cin >> n;
		memset(visited,0,sizeof(visited));

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin >> graph[i][j];
			}
		}

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(!visited[i][j]&&graph[i][j]=='x')
				{
					ans++;
					dfs(i,j,n);
				}
			}
		}

		cout << "Case " << ++k << ": " << ans << endl;

	}
	return 0;
}
