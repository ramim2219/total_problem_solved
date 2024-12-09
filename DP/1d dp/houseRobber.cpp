#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

long long int maxNumber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if (n == 0) return 0;
    if (n == 1) return valueInHouse[0];

    int prev = valueInHouse[0];
    int prev2 = 0;
    int curi;

    for (int i = 1; i < n; i++)
    {
        int take = valueInHouse[i];
        if (i > 1) take += prev2;
        int ntake = 0 + prev;
        curi = max(take, ntake);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if (n == 1) return valueInHouse[0];

    vector<int> temp1, temp2;
    for (int i = 0; i < n; i++)
    {
        if (i != 0) temp1.push_back(valueInHouse[i]);
        if (i != n - 1) temp2.push_back(valueInHouse[i]);
    }
    return max(maxNumber(temp1), maxNumber(temp2));
}

int main()
{
    fast;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = houseRobber(a);
    cout << ans << endl;
    return 0;
}

//6
//30 10 60 10 60 50
