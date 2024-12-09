#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        double s = (a + b + c) / 2.0;
        double arr = sqrt(s*(s-a)*(s-b)*(s-c));
        ll num = round(arr*arr);
        ll den = s * s;
        ll div = __gcd(num, den);
        num /= div;
        den /= div;
        cout<<num<<"/"<<den<<endl;
    }
    return 0;
}
