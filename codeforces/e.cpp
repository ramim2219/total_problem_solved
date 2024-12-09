#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
vector<ll> nums;
void calc(ll n)
{
    if(n>1e18){
        return;
    }
    if(n>0){
        nums.push_back(n);
    }
    calc(n*10+6);
    calc(n*10+9);
}
int main()
{
    fast;
    calc(0);
    sort(nums.begin(),nums.end());
    int t;
    cin>>t;
    while(t--)
    {
        ll l,r;
        cin>>l>>r;

        int left = lower_bound(nums.begin(),nums.end(),l)-nums.begin();
        int right = upper_bound(nums.begin(),nums.end(),r)-nums.begin();
        cout<<right-left<<endl;
    }
    return 0;
}
