#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    
    int windowSum = 0;
    for(int i = 0; i < k; i++) {
        windowSum += nums[i];
    }
    
    int maxSum = windowSum;
    
    for(int i = k; i < n; i++) {
        windowSum += nums[i];
        windowSum -= nums[i - k];
        
        if(windowSum > maxSum) {
            maxSum = windowSum;
        }
    }
    
    return (double)maxSum / k;
}

int main() {
    int n, k;
    
    cout << "Enter size of array: ";
    cin >> n;
    
    vector<int> nums(n);
    
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "Enter k: ";
    cin >> k;
    
    // Validation
    if(k > n || k <= 0) {
        cout << "Invalid k!" << endl;
        return 0;
    }
    
    double result = findMaxAverage(nums, k);
    
    cout << "Maximum Average: " << result << endl;
    
    return 0;
}