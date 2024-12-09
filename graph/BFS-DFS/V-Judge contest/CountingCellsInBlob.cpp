#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void bfs(int row, int col, vector<vector<int>>& vis, vector<string>& grid, int& ans) {
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});
    int cnt = 1;

    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int delrow = -1; delrow <= 1; delrow++) {
            for (int delcol = -1; delcol <= 1; delcol++) {
                int nrow = row + delrow;
                int ncol = col + delcol;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    cnt++;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    ans = max(ans, cnt);
}

int CountCellsInBlob(vector<string>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int ans = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (!vis[row][col] && grid[row][col] == '1') {
                bfs(row, col, vis, grid, ans);
            }
        }
    }
    return ans;
}

int main() {
    fast;
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();

    while (t--) {
        vector<string> grid;
        string line;

        while (getline(cin, line)) {
            if (line.empty()) break;
            grid.push_back(line);
        }


        int mainAns = CountCellsInBlob(grid);
        cout << mainAns << endl;

        if (t > 0) cout << endl;
    }

    return 0;
}
