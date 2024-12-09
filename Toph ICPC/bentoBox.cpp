#include<bits/stdc++.h>
#define ll unsigned long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
    fast;
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,c,d,x,y;
        cin>>a>>b>>c>>d;
        if((a/b==c/d)&&(a%b==c%d))
            cout<<"Equal"<<endl;
        else cout<<"Not Equal"<<endl;
    }
    return 0;
}
