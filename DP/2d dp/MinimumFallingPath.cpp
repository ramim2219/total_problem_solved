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
    cin>>n;
    vector<vector<int>>grid(n,vector<int>(n));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>grid[i][j];
        }
    }
    int ans;
    for(int i=1;i<n;i++)
    {
        ans=INT_MAX;
        for(int j=0;j<n;j++)
        {
            if(j==0)
            {
                grid[i][j]+=min(grid[i-1][j],grid[i-1][j+1]);
            }
            else if(j==n-1)
            {
                grid[i][j]+=min(grid[i-1][j],grid[i-1][j-1]);
            }
            else
            {
                grid[i][j]+=min(grid[i-1][j],min(grid[i-1][j+1],grid[i-1][j-1]));
            }
            ans=min(grid[i][j],ans);
        }
    }

    cout<<ans<<endl;
    return 0;
}
//3 3
//1 3 1
//1 5 1
//4 2 1
