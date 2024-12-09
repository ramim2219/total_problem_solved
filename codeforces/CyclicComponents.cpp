#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
void dfs(int node,vector<int>adj[],vector<int>&vis)
{
    if(vis[node]!=1)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(vis[it]==0)
                dfs(it,adj,vis);
        }
    }
}
int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+5];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n+1,0);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0 && adj[i].size()!=2)
        {
            dfs(i,adj,vis);
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            cnt++;
            dfs(i,adj,vis);
        }
    }
    cout<<cnt<<endl;
    return 0;
}
