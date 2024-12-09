#include<bits/stdc++.h>
#define ll unsigned long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
vector<ll>dp;
ll cntDigit(ll n)
{
    ll cnt=0;
    while(n!=0)
    {
        cnt++;
        n/=10;
    }
    return cnt;
}
void setDP(vector<ll>&dp)
{
    ll k=1,t=1;
    for(ll p=1;p<=1e18;)
    {
        t=p*10;
        ll r=cntDigit(t-1);
        ll total_count = 9;
        ll cnt1=0;
        ll cnt2=0;
        for(ll i=1;i<r;i++)
            cnt1+=(9*9);
        for(ll i=1;i<r;i++)
        {
            for(ll j=i+1;j<r;j++)
            {
                cnt2+=(9*9*9);
            }
        }
        total_count+=cnt1+cnt2;
        dp.push_back(total_count);
        p=p*10;
    }
}
ll makeStringNumber(string a)
{
    int num=0;
    for(int i=0;i<a.size();i++)
    {
        num = num * 10;
        num += (a[i]-'0');
    }
    return num;
}
ll r1(string s)
{
    ll total_count = s[0]-'0';
    ll cnt1=0;
    ll cnt2=0;
    for(ll i=1;i<s.size();i++)
    {
        ll xx = s[i]-'0';
        cnt1 += (xx*total_count);
    }
    for(ll i=1;i<s.size();i++)
    {
        ll xx = s[i]-'0';
        for(ll j=i+1;j<s.size();j++)
        {
            ll yy = s[j]-'0';
            cnt2+=(xx*total_count*yy);
        }
    }
    total_count += cnt1 + cnt2;
    return total_count;
}
int main()
{
    setDP(dp);
    for(int i=0;i<dp.size();i++)
        cout<<dp[i]<<endl;
    string l,r;
    cin>>l>>r;
    cout<<r1(l)<<endl;
    return 0;
}
