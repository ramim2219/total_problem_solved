#include <iostream>
using namespace std;

void solve(int case_num, long long N, int P) {
    string winner;

    // Determine the winner based on the value of N and the starting player P
    if ((N % 2 == 0 && P == 2) || (N % 2 == 1 && P == 1)) {
        // Evenius wins if N is even and Evenius starts (P==2)
        // Oddius wins if N is odd and Oddius starts (P==1)
        winner = (P == 1) ? "Oddius" : "Evenius";
    } else {
        // Otherwise, the other player wins
        winner = (P == 1) ? "Evenius" : "Oddius";
    }

    // Output the result in the specified format
    cout << "Case " << case_num << ": " << winner << endl;
}

int main() {
    int T;
    cin >> T;

    // Iterate through each test case
    for (int i = 1; i <= T; i++) {
        long long N;
        int P;
        cin >> N >> P;
        solve(i, N, P);  // Solve for each test case
    }

    return 0;
}
