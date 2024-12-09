#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
void dfs(int node,vector<int>adj[],int vis[],vector<int> &ls)
{
    vis[node] = 1;
    ls.push_back(node);
    for(auto it:adj[node])if(!vis[it])
        dfs(it,adj,vis,ls);
}

vector<int>dfsOfGraph(int V,vector<int>adj[])
{
    int vis[V+5]={0};
    int start = 1;
    vector<int> ls;
    dfs(start,adj,vis,ls);
    return ls;
}
int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+5];
    for(int i=0;i<m;i++)
    {
        char a,b;
        cin>>a>>b;
        int u,v;
        u=a-'A'+1;
        v=b-'A'+1;
        cout<<u<<" "<<v<<endl;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>ans = dfsOfGraph(n,adj);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}
