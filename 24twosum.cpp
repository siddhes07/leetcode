#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];

        if (mp.find(complement) != mp.end())
        {
            return {mp[complement], i};
        }

        mp[nums[i]] = i;
    }

    return {};
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    vector<int> result = twoSum(nums, target);

    if (result.size() == 2)
    {
        cout << result[0] << " " << result[1] << endl;
    }
    else
    {
        cout << "No solution found" << endl;
    }

    return 0;
}
