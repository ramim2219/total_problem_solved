#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
    fast;
    ll t,n,p;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>p;
        cout<<"Case "<<i<<": ";
        if(n==1 && p==1)cout<<"Evenius "<<endl;
        else cout<<"Oddius "<<endl;
    }
    return 0;
}
