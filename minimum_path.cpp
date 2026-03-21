#include <iostream>
#include <vector>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    
    // Copy last row into dp array
    vector<int> dp = triangle[n - 1];

    // Bottom-up calculation
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        }
    }

    return dp[0];
}

int main() {
    vector<vector<int>> triangle;
    int n;

    cout << "Enter number of rows: ";
    cin >> n;

    triangle.resize(n);

    cout << "Enter triangle elements row-wise:\n";
    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }

    int result = minimumTotal(triangle);
    cout << "Minimum Path Sum = " << result << endl;

    return 0;
}