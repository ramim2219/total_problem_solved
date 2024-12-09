#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main() {
    fast;
    int t;
    cin>>t;
    for(int p=1;p<=t;p++)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> arr;
        for (int i = 0; i < n; i++) {
            vector<ll> row;
            for (int j = 0; j <= i; j++) {
                ll p;
                cin >> p;
                row.push_back(p);
            }
            arr.push_back(row);
        }

        for (int i = n - 2; i >= 0; i--) {
            vector<ll> row;
            for (int j = 0; j <= i; j++) {
                ll p;
                cin >> p;
                row.push_back(p);
            }
            arr.push_back(row);
        }
        int total_rows = arr.size();
        vector<vector<ll>> dp(total_rows, vector<ll>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (i == 0) {
                    dp[i][j] = arr[i][j];
                } else if (j == 0) {
                    dp[i][j] = arr[i][j] + dp[i - 1][j];
                } else if (j == i) {
                    dp[i][j] = arr[i][j] + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
                }
            }
        }
        for (int i = n; i < total_rows; i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                dp[i][j] = arr[i][j] + max(dp[i - 1][j], dp[i - 1][j + 1]);
            }
        }
        ll result = dp[total_rows - 1][0];
        cout <<"Case "<<p<<": "<< result << endl;

    }
    return 0;
}
