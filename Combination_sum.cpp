
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        sort(candidates.begin(), candidates.end());

        solve(0, target, candidates, current, ans);

        return ans;
    }

    void solve(int index, int target, vector<int>& candidates,
               vector<int>& current, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicate elements at the same level
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted
            if (candidates[i] > target)
                break;

            current.push_back(candidates[i]);

            // i + 1 means each element is used only once
            solve(i + 1, target - candidates[i],
                  candidates, current, ans);

            current.pop_back();
        }
    }
};

int main() {
    Solution sol;

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> result =
        sol.combinationSum2(candidates, target);

    cout << "Combinations are:\n";

    for (const auto& combination : result) {
        cout << "[";
        for (int i = 0; i < combination.size(); i++) {
            cout << combination[i];
            if (i < combination.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}
