#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int, int>>> &adj, int S) {
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);

    st.insert({0, S});
    dist[S] = 0;

    while (!st.empty()) {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for (auto it : adj[node]) {
            int adjNode = it.first;
            int edgW = it.second;

            if (dis + edgW < dist[adjNode]) {
                st.erase({dist[adjNode], adjNode});
                dist[adjNode] = dis + edgW;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

int main() {
    fast;
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int>>> adj(V);

    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int src;
    cin >> src;
    vector<int> res = dijkstra(V, adj, src);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }

    return 0;
}

//5 6
//0 1 2
//0 2 4
//1 2 1
//1 3 7
//2 4 3
//3 4 1
//0
