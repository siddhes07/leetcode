#include <iostream>
using namespace std;


bool isPowerOfTwo(int n) {
    if (n <= 0)
        return false;

    while (n % 2 == 0) {
        n = n / 2;
    }

    return (n == 1);
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (isPowerOfTwo(num))
        cout << "Power of 2";
    else
        cout << "Not a power of 2";

    return 0;
}
