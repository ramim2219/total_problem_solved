#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
using namespace std;
const int N = 1e5+5;
vector<int> g[N];
vector<bool> vis(N);
vector<int> cat(N);
int ans = 0;
void dfs( int node, int cnt, int c )
{
    bool leafNode = true;
    vis[node] = true;
    for( auto child : g[node] ) {
        if( vis[child] == false ) {
            if( cat[child] ) {
                if(cnt + 1 <= c ) {
                    dfs(child, cnt + 1,c);
                }
            }
            else {
                dfs(child,0,c);
            }
            leafNode=false;
        }
    }
    if( leafNode && cnt <= c ) ans += 1;
    return ;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, c; cin >> n >> c;
    for(int i = 1; i <= n; i += 1 ) {
        cin >> cat[i];
    }
    for( int i = 1; i <= (n-1) ; i += 1 ) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, cat[1], c);
    cout << ans << endl;
    return 0;
}
//4 1
//1 1 0 0
//1 2
//1 3
//1 4

//12 2
//1 0 0 1 1 1 0 1 0 0 1 0
//1 2
//1 3
//2 4
//2 5
//3 6
//3 7
//4 8
//5 9
//6 10
//11 12
//7 11
