#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mk make_pair


vector<vector<ll>>x;
bool vis[105];
ll ans=1;

void dfs(ll n, ll pa)
{
    if(n!=pa)
    {
        ans*=2;
    }
    vis[n] = 1;
    for(int i=0;i<x[n].size();i++)
    {
        ll lol = x[n][i];
        if(!vis[lol])
        {
            dfs(lol, pa);
        }
    }
}


int main()
{
    ll n,m;
    cin>>n>>m;
    x.resize(n+5);
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        x[a].push_back(b);
        x[b].push_back(a);
    }    

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i, i);
        }
    }

    cout<<ans<<endl;

    return 0;
}
