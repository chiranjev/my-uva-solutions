#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007

using namespace std;

ll memo[6][30001];
int coinValue[5]={1,5,10,25,50};

ll ways(int type,int value)
{
  if(value==0)
    return 1;
  if(value<0||type==5)
    return 0;
  if(memo[type][value]!=-1)
    return memo[type][value];
  return memo[type][value]=ways(type+1,value)+ways(type,value-coinValue[type]);
}

int main()
{
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    ll num;

    memset(memo,-1,sizeof(memo));

    while(cin >> n)
    {

      num=ways(0,n);
      if(num==1)
        cout << "There is only 1 way to produce " << n << " cents change." << endl;
      else
        cout << "There are " << num << " ways to produce " << n << " cents change." << endl;
    }

    return 0;
}