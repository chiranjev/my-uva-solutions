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

    int n,k,i,v,cost,lines;
    char c,ch;
    string s;
    cin >> n;
    map<int,int> mp;
    while(n--)
    {
        cin >> k;
        cost=0;
        mp.clear();
        for(i=0;i<k;i++)
        {
            cin >> c >> v;

            mp[c]=v;
        }
        cin >> lines;
        getline(cin,s);
        while(lines--)
        {
            getline(cin,s);
            for(i=0;i<s.length();i++)
              cost+=mp[s[i]];
        }
        printf("%.2f$\n",cost/100.0);
    }


    return 0;

}
