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
        int left = dp[i-1]+abs(a[i]-a[i-1]);
        int right = INT_MAX;
        if(i>1)
            right = dp[i-2]+abs(a[i]-a[i-2]);
        dp[i]=min(left,right);
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
