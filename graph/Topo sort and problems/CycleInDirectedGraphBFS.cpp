#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool check(int V, vector<int>adj[])
{
    int indegree[V]={0};
    for(int i=0;i<V;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    int  cnt=0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        for(auto it: adj[node])
        {
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
    }
    if(cnt==V)return false;
    else return true;
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
    }
    if(check(n,adj))
        cout<<"Cycle"<<endl;
    else cout<<"Not Cycle"<<endl;
    return 0;
}
//6 6
//5 0
//5 2
//2 3
//3 1
//4 1
//4 0
