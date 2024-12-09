#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;

// Function for modular exponentiation
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// Miller-Rabin Primality Test
bool millerRabin(long long n, int k = 5) {
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n == 1) return false;

    // Write n-1 as d * 2^r
    long long d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    // Witness loop
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<long long> dis(2, n - 2);

    for (int i = 0; i < k; i++) {
        long long a = dis(gen);
        long long x = modExp(a, d, n);
        if (x == 1 || x == n - 1) continue;

        bool found = false;
        for (int j = 0; j < r - 1; j++) {
            x = (x * x) % n;
            if (x == n - 1) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}
ll countDivisors(ll t) {
    ll cnt = 1;
    if(millerRabin(t))return 2;
    if (t % 2 == 0) {
        ll power = 0;
        while (t % 2 == 0) {
            t /= 2;
            power++;
        }
        cnt *= (power + 1);
    }
    if(millerRabin(t))return cnt;
    for (ll i = 3; i * i <= t; i += 2) {
        if (t % i == 0) {
            ll power = 0;
            while (t % i == 0) {
                t /= i;
                power++;
            }
            cnt *= (power + 1);
            if(millerRabin(t))return cnt;
        }
    }
    if (t > 1) cnt *= 2;

    return cnt;
}
int main() {
    ll t;
    cin>>t;
    ll ans = countDivisors(t);
    cout<<ans<<endl;
    return 0;
}
