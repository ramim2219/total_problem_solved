#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int climbStairs(int n) {
    int dp[n+5];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main()
{
    fast;
    int n;
    cin>>n;
    int ans = climbStairs(n);
    cout<<ans<<endl;
    return 0;
}
