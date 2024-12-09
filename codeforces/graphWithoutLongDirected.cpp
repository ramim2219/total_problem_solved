#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&image,int newColor ,int delRow[],int delCol[],int iniColor)
{
    ans[row][col] = newColor;
    int n=image.size();
    int m=image[0].size();
    for(int i=0;i<4;i++)
    {
        int nrow = row+delRow[i];int ncol = col + delCol[i];//4 direction traverse
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iniColor && ans[nrow][ncol]!=newColor)
        {
            dfs ( nrow , ncol , ans , image , newColor,delRow,delCol,iniColor);
        }
    }
}

vector<vector<int>>floodFill(vector<vector<int>>&image,int sr,int sc,int newColor)
{
    int iniColor = image[sr][sc];
    vector<vector<int>> ans = image;
    int delRow[] = {-1,0,1,0};int delCol[] = {0,1,0,-1};
    dfs(sr,sc,ans,image,newColor,delRow,delCol,iniColor);
    return ans;
}
int main()
{
    fast;
    int n,m;
    cin>>n>>m;
    vector<vector<int>>image(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {

        }
    }
    return 0;
}
