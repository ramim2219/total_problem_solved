#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
    fast;
    int n;
    cin>>n;
    vector<vector<int>>pp;
    for(int i=0;i<n;i++)
    {
        vector<int>xx;
        for(int j=0;j<=i;j++)
        {
            int p;
            cin>>p;
            xx.push_back(p);
        }
        pp.push_back(xx);
    }
    int ans;
    for(int i=1;i<n;i++)
    {
        int m=pp[i].size();
        ans=INT_MAX;
        for(int j=0;j<m;j++)
        {
            if(j==0)pp[i][j]+=pp[i-1][j];
            else if(j==m-1)pp[i][j]+=pp[i-1][j-1];
            else pp[i][j]+=min(pp[i-1][j-1],pp[i-1][j]);
            ans=min(ans,pp[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        int m=pp[i].size();
        for(int j=0;j<m;j++)
        {
            cout<<pp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
//4
//2
//3 4
//6 5 7
//4 1 8 3
