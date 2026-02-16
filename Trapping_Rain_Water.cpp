#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int leftMax = 0, rightMax = 0, water = 0;

    while (l < r) {
        if (height[l] < height[r]) {
            if (height[l] >= leftMax)
                leftMax = height[l];
            else
                water += leftMax - height[l];
            l++;
        } else {
            if (height[r] >= rightMax)
                rightMax = height[r];
            else
                water += rightMax - height[r];
            r--;
        }
    }
    return water;
}

int main() {
    vector<int> h = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Water Trapped: " << trap(h);
}