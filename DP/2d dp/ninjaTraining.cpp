#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
    fast;
    int n,m;
    m=3;
    cin>>n;
    vector<vector<int>>grid(n,vector<int>(3));
    for(int i=0;i<n;i++)
        for(int j=0;j<3;j++)
            cin>>grid[i][j];
    int x,maxi = INT_MIN;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j==0)
                x=max(grid[i-1][1],grid[i-1][2]);
            else if(j==1)
                x=max(grid[i-1][0],grid[i-1][2]);
            else if(j==2)
                x=max(grid[i-1][1],grid[i-1][0]);
            grid[i][j]=x+grid[i][j];
            maxi=max(maxi,grid[i][j]);
        }
    }
    cout<<maxi<<endl;
    return 0;
}
