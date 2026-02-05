#include <iostream>
using namespace std;

// Function to find the highest altitude
int largestAltitude(int gain[], int n) {
    int maxAltitude = 0;
    int currentAltitude = 0;

    for (int i = 0; i < n; i++) {
        currentAltitude += gain[i];
        if (currentAltitude > maxAltitude) {
            maxAltitude = currentAltitude;
        }
    }

    return maxAltitude;
}

int main() {
    int n;

    cout << "Enter the number of elements in the gain array: ";
    cin >> n;

    int gain[n];

    cout << "Enter the elements of the gain array:\n";
    for (int i = 0; i < n; i++) {
        cin >> gain[i];
    }

    int highest = largestAltitude(gain, n);
    cout << "The highest altitude is: " << highest << endl;

    return 0;
}
