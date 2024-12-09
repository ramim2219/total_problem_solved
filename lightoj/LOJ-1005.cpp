#include<bits/stdc++.h>
#define ll unsigned long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
    fast;
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ll n,k;
        cin>>n>>k;
        ll ans = 1;
        if(k>n)cout<<"Case "<<i<<": "<<0<<endl;
        else
        {
            for(ll j=0;j<k;j++)
            {
                ans *= (n-j);
            }
            ll kx=1;
            ll ans2 = ans;
            for(ll j=2;j<=k;j++)kx*=j;
            ans = ans/kx;
            ans *= ans2;
            cout<<"Case "<<i<<": "<<ans<<endl;
        }
    }
    return 0;
}
