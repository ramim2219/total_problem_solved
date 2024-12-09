#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int bfsOfGraph(int n, int m) {
    if (n >= m) {
        return n - m;
    }

    queue<int> q;
    unordered_set<int> visited;
    q.push(n);
    visited.insert(n);
    int level = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int current = q.front();
            q.pop();

            if (current == m) {
                return level;
            }
            int x = current - 1;
            int y = current * 2;

            if (x > 0 && visited.find(x) == visited.end()) {
                q.push(x);
                visited.insert(x);
            }
            if (y <= 2 * m && visited.find(y) == visited.end()) {
                q.push(y);
                visited.insert(y);
            }
        }
        level++;
    }

    return -1;
}

int main() {
    fast;
    int n, m;
    cin >> n >> m;
    int ans = bfsOfGraph(n, m);
    cout << ans << endl;
    return 0;
}
