#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

ll countDivisors(ll t) {
    ll cnt = 1;
    if (t % 2 == 0) {
        ll power = 0;
        while (t % 2 == 0) {
            t /= 2;
            power++;
        }
        cnt *= (power + 1);
    }
    for (ll i = 3; i * i <= t; i += 2) {
        if (t % i == 0) {
            ll power = 0;
            while (t % i == 0) {
                t /= i;
                power++;
            }
            cnt *= (power + 1);
        }
    }
    if (t > 1) cnt *= 2;

    return cnt;
}

int main() {
    fast;
    ll t;
    cin >> t;

    cout << countDivisors(t) << endl;
    return 0;
}
