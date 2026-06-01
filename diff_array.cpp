#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> res1, res2;

        for (int x : set1)
            if (!set2.count(x))
                res1.push_back(x);

        for (int x : set2)
            if (!set1.count(x))
                res2.push_back(x);

        return {res1, res2};
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};

    vector<vector<int>> result = sol.findDifference(nums1, nums2);

    cout << "Test Case 1:" << endl;
    cout << "nums1 = [1, 2, 3], nums2 = [2, 4, 6]" << endl;
    cout << "answer[0] (in nums1 not nums2): [";
    for (int i = 0; i < result[0].size(); i++)
        cout << result[0][i] << (i + 1 < result[0].size() ? ", " : "");
    cout << "]" << endl;

    cout << "answer[1] (in nums2 not nums1): [";
    for (int i = 0; i < result[1].size(); i++)
        cout << result[1][i] << (i + 1 < result[1].size() ? ", " : "");
    cout << "]" << endl;

    cout << endl;

    // Test Case 2
    vector<int> nums3 = {1, 2, 3, 3};
    vector<int> nums4 = {1, 1, 2, 2};

    result = sol.findDifference(nums3, nums4);

    cout << "Test Case 2:" << endl;
    cout << "nums1 = [1, 2, 3, 3], nums2 = [1, 1, 2, 2]" << endl;
    cout << "answer[0] (in nums1 not nums2): [";
    for (int i = 0; i < result[0].size(); i++)
        cout << result[0][i] << (i + 1 < result[0].size() ? ", " : "");
    cout << "]" << endl;

    cout << "answer[1] (in nums2 not nums1): [";
    for (int i = 0; i < result[1].size(); i++)
        cout << result[1][i] << (i + 1 < result[1].size() ? ", " : "");
    cout << "]" << endl;

    return 0;
}