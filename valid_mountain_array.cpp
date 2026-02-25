#include <iostream>
#include <vector>
using namespace std;

bool validMountainArray(vector<int>& arr) {
    int n = arr.size();
    if (n < 3) return false;

    int i = 0;

    // Walk up
    while (i + 1 < n && arr[i] < arr[i + 1])
        i++;

    // Peak can't be first or last
    if (i == 0 || i == n - 1) return false;

    // Walk down
    while (i + 1 < n && arr[i] > arr[i + 1])
        i++;

    return i == n - 1;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (validMountainArray(arr))
        cout << "The array is a valid mountain array.\n";
    else
        cout << "The array is NOT a valid mountain array.\n";

    return 0;
}