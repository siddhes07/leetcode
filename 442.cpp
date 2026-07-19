#include <iostream>
#include <vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;

    for (int i = 0; i < nums.size(); i++) {
        int index = abs(nums[i]) - 1;

        if (nums[index] < 0)
            ans.push_back(index + 1);
        else
            nums[index] = -nums[index];
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = findDuplicates(nums);

    cout << "Duplicate elements: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
