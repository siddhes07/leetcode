#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {8, 1, 2, 2, 3};
    int n = nums.size();

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (nums[j] < nums[i]) {
                ans[i]++;
            }
        }
    }

    cout << "Output: ";
    for (int x : ans) {
        cout << x << " ";
    }

    return 0;
}
