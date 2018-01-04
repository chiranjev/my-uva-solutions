#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

int visited[25][25],graph[25][25];

bool isValid(int i,int j,int n)
{
	if(i<n&&i>=0&&j<n&&j>=0)
		return true;
	return false;
}

int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,-1,1,-1,0,1};

void dfs(int x,int y,int n)
{
	for(int i=0;i<8;i++)
	{
		if(isValid(x+dx[i],y+dy[i],n)&&!visited[x+dx[i]][y+dy[i]]&&graph[x+dx[i]][y+dy[i]]==1)
		{
			visited[x+dx[i]][y+dy[i]]=1;
			dfs(x+dx[i],y+dy[i],n);
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
	int t;
	char c;
	k=0;
	while(cin >> n)
	{
		count=0;
		memset(graph,0,sizeof(graph));
		memset(visited,0,sizeof(visited));

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
					cin >> c;
					if(c=='0')
						graph[i][j]=0;
					else
						graph[i][j]=1;
			}
		}

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(!visited[i][j]&&graph[i][j]==1)
				{
					dfs(i,j,n);
					count++;
				}
			}
		}
		cout << "Image number " << ++k << " contains " << count << " war eagles." << endl;

	}


	return 0;
}
