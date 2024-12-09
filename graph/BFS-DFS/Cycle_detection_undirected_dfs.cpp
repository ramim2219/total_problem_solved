#include <bits/stdc++.h>
using namespace std;
bool dfs(int node,int parent,int vis[], vector<int>adj[]){vis[node]=1;

    for(auto adjacentNode:adj[node]){

        if(!vis[adjacentNode]){

           if(dfs(adjacentNode,node,vis,adj)==true)

               return true;}

         else if(adjacentNode != parent) return true;}

    return false;

}

bool isCycle(int V,vector<int>adj[]){

   int vis[V] = {0};

   for(int i = 0;i<V;i++){

       if(!vis[i]){

           if(dfs(i, -1, vis, adj) == true) return true;}}

    return false;

}

int main() {

    // V = 4, E = 2
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool ans = isCycle(n, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}
//7 6
//1 2
//2 5
//5 7
//7 6
//6 3
