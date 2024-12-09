#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int frog_jump(int n,int k,vector<int>a)
{
    int dp[n+5]={0};
    for(int i=1;i<n;i++)
    {
        int jump;
        int mn_steps = INT_MAX;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                jump = dp[i-j]+abs(a[i]-a[i-j]);
                mn_steps=min(mn_steps,jump);
            }
        }
        dp[i]=mn_steps;
    }
    return dp[n-1];
}
int main()
{
    fast;
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int ans = frog_jump(n,k,a);
    cout<<ans<<endl;
    return 0;
}
