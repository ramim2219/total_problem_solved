#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
    fast;
    string s,t;
    string st="";
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    int curr=0;
    for(int i=1;i<=n;i++)
    {
        cout<<t[i]<<" ";
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                if(curr<dp[i][j])
                {
                   st = st+s[i-1];
                   curr = dp[i][j];
                }
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<st<<endl;
    return 0;
}
//adebc
//dcadb
