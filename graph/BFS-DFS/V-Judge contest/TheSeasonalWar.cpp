#include <bits/stdc++.h>
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void bfs(int row, int col, vector<vector<int>>& vis, const vector<vector<char>>& grid) {
    int n = grid.size();
    vis[row][col] = 1;
    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int delRow = -1; delRow <= 1; delRow++) {
            for (int delCol = -1; delCol <= 1; delCol++) {
                int newRow = r + delRow;
                int newCol = c + delCol;
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
}

int numIslands(const vector<vector<char>>& grid) {
    int n = grid.size();
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int count = 0;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (!vis[row][col] && grid[row][col] == '1') {
                count++;
                bfs(row, col, vis, grid);
            }
        }
    }
    return count;
}

int main() {
    fast;
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    if (!inputFile || !outputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int imageNumber = 1;
    int n;
    while (inputFile >> n) {
        vector<vector<char>> grid(n, vector<char>(n));
        inputFile.ignore();

        for (int i = 0; i < n; i++) {
            string line;
            getline(inputFile, line);
            for (int j = 0; j < n; j++) {
                grid[i][j] = line[j];
            }
        }

        int result = numIslands(grid);
        outputFile << "Image number " << imageNumber << " contains " << result << " war eagles." << endl;
        imageNumber++;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
