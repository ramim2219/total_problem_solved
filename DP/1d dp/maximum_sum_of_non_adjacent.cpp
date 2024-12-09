#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

int usingRecursion(int ind, vector<int>& a, vector<int>& dp)
{
    if (ind == 0) return a[ind];
    else if (ind < 0) return 0;
    else if (dp[ind] != -1) return dp[ind];

    int pick = a[ind] + usingRecursion(ind - 2, a, dp);
    int notpick = usingRecursion(ind - 1, a, dp);

    return dp[ind] = max(pick, notpick);
}
int usingTabulation(int n,vector<int>&a)
{
    vector<int>dp(n);
    int take,nottake;
    dp[0]=a[0];
    for(int i=1;i<n;i++)
    {
        if(i-2>=0)take = a[i]+dp[i-2];
        else take = a[i] ;
        nottake = 0 + dp[i-1];
        dp[i]=max(take,nottake);
    }
    return dp[n-1];
}

int main()
{
    fast;
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp(n, -1);
    int ans = usingRecursion(n-1, a, dp);
    int ans2 = usingTabulation(n,a);
    cout << ans << endl;
    cout << ans2 << endl;
    return 0;
}
//6
//30 10 60 10 60 50
