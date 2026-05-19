#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long maximumTotalCost(vector<int>& nums) {
    int n = nums.size();
    long long same = nums[0];
    long long diff = nums[0];

    for (int i = 1; i < n; i++) {
        long long newSame = max(same, diff) + nums[i];
        long long newDiff = same - nums[i];

        same = newSame;
        diff = newDiff;
    }

    return max(same, diff);
}

int main() {
    // Test Case 1
    vector<int> nums1 = {1, -2, 3, -4};
    cout << "Output 1: " << maximumTotalCost(nums1) << endl;
    // Expected: 10

    // Test Case 2
    vector<int> nums2 = {1, -1, 1, -1};
    cout << "Output 2: " << maximumTotalCost(nums2) << endl;
    // Expected: 4

    return 0;
}