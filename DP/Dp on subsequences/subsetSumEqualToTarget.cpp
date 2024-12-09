#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool subsetSumToK(int n, int k, vector<int> &arr,vector<vector<int>>&dp) {
    if(k==0)return true;
    if(n==0)return (arr[0]==k);
    if(dp[n][k]!=-1)return dp[n][k];
    bool notTake = subsetSumToK(n-1,k,arr,dp);
    bool take = false;
    if(arr[n]<=k)
        take = subsetSumToK(n-1,k-arr[n],arr,dp);
    return dp[n][k] = take | notTake;
}
int main()
{
    fast;
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    if(subsetSumToK(n-1,k,arr,dp))
        cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
//5 8
//2 5 1 6 7
