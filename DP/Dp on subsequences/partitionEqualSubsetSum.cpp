#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
bool subsetSumToK(int n, int k, vector<int> &arr,vector<vector<int>>&dp) {

if(k==0)return true;if(n==0)return (arr[0]==k);

if(dp[n][k]!=-1)return dp[n][k];

bool notTake = subsetSumToK(n-1,k,arr,dp);bool take = false;if(arr[n]<=k)take = subsetSumToK(n-1,k-arr[n],arr,dp);return dp[n][k] = take | notTake;}

int main(){fast;int n,k;cin>>n;vector<int>arr(n);int s=0;for(int i=0;i<n;i++){cin>>arr[i];s+=arr[i];}

if(s%2==1)cout<<"NO"<<endl;

else{k=s/2;vector<vector<int>>dp(n,vector<int>(k+1,-1));if(subsetSumToK(n-1,k,arr,dp)) cout<<"YES"<<endl;else cout<<"NO"<<endl;}}
//5
//4 2 5 1 6
