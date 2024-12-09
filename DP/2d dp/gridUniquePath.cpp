//count unique paths
//count paths with obstacle
//min path sum
//max path sum
//triangle
//2 start points
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
    vector<vector<int>>dp(n,vector<int>(m,0));
    vector<vector<int>>grid(n,vector<int>(m));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=1;
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<dp[n-1][m-1]<<endl;
    return 0;
}
//2 2
//0 1
//0 0

//3 3
//0 0 0
//0 1 0
//0 0 0

//1 6
//0 0 1 0 0 0


