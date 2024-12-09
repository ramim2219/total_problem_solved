#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
    fast;
    int n,m;
    cin>>n>>m;

    //this is the graph stored in array
//    int adj[n+1][m+1];
//    for(int i=0;i<m;i++)
//    {
//        int u,v;
//        cin>>u>>v;
//        adj[u][v]=1;
//        adj[v][u]=1;
//    }

    //this is the graph stored in vector
    vector<int>adj[n+1];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}
