#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int numTrees(int n) {

        vector<int> dp(n + 1, 0);

        dp[0] = 1;
        dp[1] = 1;

        // Calculate for all nodes from 2 to n
        for (int nodes = 2; nodes <= n; nodes++) {

            for (int root = 1; root <= nodes; root++) {

                int left = dp[root - 1];
                int right = dp[nodes - root];

                dp[nodes] += left * right;
            }
        }

        return dp[n];
    }
};

int main() {

    Solution obj;

    int n;

    cout << "Enter n: ";
    cin >> n;

    int ans = obj.numTrees(n);

    cout << "Number of Unique BSTs: " << ans << endl;

    return 0;
}