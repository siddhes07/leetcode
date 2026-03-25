#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40};
    int key = 30;
    int n = 4;

    int index = linearSearch(arr, n, key);

    if(index != -1)
        cout << "Found at index: " << index;
    else
        cout << "Not found";

    return 0;
}
