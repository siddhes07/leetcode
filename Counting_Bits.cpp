#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i >> 1] + (i & 1);
    }

    return dp;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> result = countBits(n);

    cout << "Counting bits from 0 to " << n << ":\n";
    for (int i = 0; i <= n; i++) {
        cout << result[i] << " ";
    }

    return 0;
}