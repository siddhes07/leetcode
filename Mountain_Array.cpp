#include <iostream>
#include <vector>
using namespace std;

bool validMountainArray(vector<int>& arr) {
    int n = arr.size();
    
    if (n < 3) return false;

    int i = 0;

    // Increasing part
    while (i + 1 < n && arr[i] < arr[i + 1]) {
        i++;
    }

    // Peak should not be first or last
    if (i == 0 || i == n - 1) return false;

    // Decreasing part
    while (i + 1 < n && arr[i] > arr[i + 1]) {
        i++;
    }

    return i == n - 1;
}

int main() {
    vector<int> arr = {0, 3, 2, 1};

    if (validMountainArray(arr)) {
        cout << "Valid Mountain Array" << endl;
    } else {
        cout << "Not a Valid Mountain Array" << endl;
    }

    return 0;
}