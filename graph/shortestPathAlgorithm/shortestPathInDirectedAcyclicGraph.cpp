#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

vector<int> topoSort(int V, vector<pair<int, int>> adj[]) {
    int indegree[V] = {0};

    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it.first]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for (auto it : adj[node]) {
            indegree[it.first]--;
            if (indegree[it.first] == 0)
                q.push(it.first);
        }
    }
    return topo;
}

int main() {
    fast;
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }
    vector<int> topo = topoSort(n, adj);
    vector<int> wt(n, INT_MAX);
    wt[0] = 0;
    for (int i = 0; i < topo.size(); i++) {
        int node = topo[i];

        if (wt[node] != INT_MAX) {
            for (auto it : adj[node]) {
                int v = it.first;
                int weight = it.second;
                wt[v]=min(wt[node] + weight,wt[v]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        wt[i] = (wt[i]==INT_MAX) ? -1 : wt[i];
    }

    return 0;
}


//6 7
//0 1 2
//0 4 1
//4 5 4
//4 2 2
//1 2 3
//2 3 6
//5 3 1
//0 1 4 5 2 3

//7 8
//6 4 2
//6 5 3
//5 4 1
//4 0 3
//4 2 1
//0 1 2
//2 3 3
//1 3 1
