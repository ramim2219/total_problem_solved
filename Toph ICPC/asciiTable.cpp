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
    for(int j=1;j<=t;j++)
    {
        cout<<"Case "<<j<<":"<<endl;
        int n=94;
        char a,b;
        cin>>a>>b;
        int p = a-'!'+1;
        int q = b-'!'+1;
        for(int i=1;i<n/2;i++)
        {
            if(p%i == q%i)
            {
                if(n%i==0)
                    cout<<i<<" "<<n/i<<endl;
                else
                    cout<<i<<" "<<n/i+1<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
