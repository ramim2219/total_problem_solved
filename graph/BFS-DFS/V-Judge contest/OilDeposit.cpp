#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
void bfs(int row, int col, vector<vector<int>>&vis , vector<vector<char>>grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vis[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row,col});
    while(!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        //8 directional traverse
        for(int delrow=-1;delrow<=1;delrow++)
        {
            for(int delcol=-1;delcol<=1;delcol++)
            {
                int nrow = row + delrow;
                int ncol = col + delcol;
                if(nrow>=0 && nrow<n && ncol>=0 &&
                   ncol<m && grid[nrow][ncol]=='@'
                   && !vis[nrow][ncol])
                   {
                       vis[nrow][ncol] = 1;
                       q.push({nrow,ncol});
                   }
            }
        }
    }
}
int OilDeposit(vector<vector<char>>& grid)
{
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    int cnt=0;
    for(int row=0;row<n;row++)
    {
        for(int col=0;col<m;col++)
        {
            if(!vis[row][col] && grid[row][col]=='@')
            {
                cnt++;
                bfs(row,col,vis,grid);
            }
        }
    }
    return cnt;
}
int main()
{
    fast;
    int n,m;
    while(1)
    {
        cin>>n>>m;
        if(n==0 && m==0)break;
        vector<vector<char>>grid(n,vector<char>(m));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>grid[i][j];
        int ans = OilDeposit(grid);
        cout<<ans<<endl;
    }
    return 0;
}
//6 5
//00110
//00110
//10010
//00000
//11001
//10001
