#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool check(int start,int V,vector<int>adj[],int color[])
{
    color[start]=0;
    queue<int>q;
    q.push(start);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it: adj[node])
        {
            if(color[it]==-1)
            {
                color[it]= !color[node];
                q.push(it);
            }
            else if(color[it]==color[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int V,vector<int>adj[])
{
    int color[V];
    for(int i=0;i<V;i++)color[i]=-1;
    for(int i=0;i<V;i++)
    {
        if(color[i]==-1)
        {
            if(check(i,V,adj,color)==false)
                return false;
        }
    }
    return true;
}
int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isBipartite(n,adj))cout<<"Bipartite"<<endl;
    else cout<<"Not Bipartite"<<endl;
    return 0;
}
