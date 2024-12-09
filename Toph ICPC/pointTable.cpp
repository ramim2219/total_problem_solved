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
        int a[3];
        for(int i=0;i<3;i++)
            cin>>a[i];
        sort(a,a+3);
        bool valid = false;
        if(a[0]==0 && a[1]==3 && a[2]==6)valid = true;
        else if(a[0]==1 && a[1]==1 && a[2]==6)valid = true;
        else if(a[0]==1 && a[1]==3 && a[2]==4)valid = true;
        else if(a[0]==1 && a[1]==2 && a[2]==4)valid = true;
        else if(a[0]==0 && a[1]==4 && a[2]==4)valid = true;
        else if(a[0]==3 && a[1]==3 && a[2]==3)valid = true;
        else if(a[0]==2 && a[1]==2 && a[2]==2)valid = true;
        if(valid)cout<<"Case "<<j<<": perfectus"<<endl;
        else cout<<"Case "<<j<<": invalidum"<<endl;
    }
    return 0;
}
