#include <iostream>
using namespace std;


void twoSum(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                cout << "Index: " << i << " and " << j << endl;
                return;
            }
        }
    }
    cout << "No pair found";
}

int main() {
    int n, target;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    twoSum(arr, n, target);

    return 0;
}
