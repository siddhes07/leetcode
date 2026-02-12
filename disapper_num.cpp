#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;

    // Count frequency
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Print elements that appear once
    for(int i = 0; i < n; i++) {
        if(freq[arr[i]] == 1) {
            cout << arr[i] << " ";
        }
    }

    return 0;
}
