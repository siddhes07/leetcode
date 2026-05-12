#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void solve(int start, int n, int k, vector<int>& temp) {
        // Base case
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        // Generate combinations
        for (int i = start; i <= n; i++) {
            temp.push_back(i);
            solve(i + 1, n, k, temp);
            temp.pop_back(); // backtrack
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1, n, k, temp);
        return ans;
    }
};

int main() {
    int n, k;

    cout << "Enter n and k: ";
    cin >> n >> k;

    Solution obj;
    vector<vector<int>> result = obj.combine(n, k);

    cout << "Combinations are:\n";

    for (auto &vec : result) {
        cout << "[ ";
        for (int x : vec) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}
