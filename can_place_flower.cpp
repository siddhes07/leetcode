#include <iostream>
using namespace std;

// Function 1: check if flower can be placed at index i
bool canPlaceAt(int bed[], int size, int i) {
    if (bed[i] == 1)
        return false;

    if (i > 0 && bed[i - 1] == 1)
        return false;

    if (i < size - 1 && bed[i + 1] == 1)
        return false;

    return true;
}

// Function 2: check if k flowers can be placed
bool canPlaceFlowers(int bed[], int size, int k) {
    for (int i = 0; i < size; i++) {
        if (canPlaceAt(bed, size, i)) {
            bed[i] = 1;
            k--;
        }
        if (k <= 0)
            return true;
    }
    return false;
}

int main() {
    int size, k;

    cout << "Enter size of matrix: ";
    cin >> size;

    int bed[size];

    cout << "Enter matrix values (0 or 1):\n";
    for (int i = 0; i < size; i++) {
        cin >> bed[i];
    }

    cout << "Enter number of flowers to place: ";
    cin >> k;

    if (canPlaceFlowers(bed, size, k))
        cout << "TRUE : flowers can be placed\n";
    else
        cout << "FALSE : flowers cannot be placed\n";

    return 0;
}
