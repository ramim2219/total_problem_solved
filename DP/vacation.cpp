#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int a[n+5];
        vector<vector<int>>dp(n,vector<int>(3,0));
        char pp;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==0)
            {
                if(i==0)
                    dp[i][0]++;
                else
                    dp[i][0]=dp[i-1][0]+1;
                pp='r';
            }
            else if(a[i]==1)
            {
                if(i==0)
                    dp[i][2]++;
                else if(pp!='c')
                {
                    dp[i][2]=1+dp[i-1][2];
                    pp='c';
                }
                else
                {
                    dp[i][0]=dp[i-1][0]+1;
                }
            }
            else if(a[i]==2)
            {

            }
            else if(a[i]==3)
            {

            }
        }
    }
    return 0;
}
