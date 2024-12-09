#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
void revPyramid(ll sp,ll n)
{
    if(n<0)return ;
    else{
        int x=2*n+1;
        for(int i=0;i<sp;i++)cout<<" ";
        for(int i=0;i<=n;i++)
            cout<<"**";
        cout<<endl;
        revPyramid(sp+1,n-1);
    }
}
int main()
{
    fast;
    ll t;
    cin>>t;
    for(ll p=1;p<=t;p++)
    {
        ll n;
        cin>>n;
        n--;
        int sp=0;
        revPyramid(sp,n);
    }
    return 0;
}
