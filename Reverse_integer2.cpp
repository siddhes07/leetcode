#include <iostream>
#include <climits>
using namespace std;

int reverse(int x) {
    long long rev = 0;

    while (x != 0) {
        int digit = x % 10;
        rev = rev * 10 + digit;

        if (rev > INT_MAX || rev < INT_MIN)
            return 0;

        x /= 10;
    }

    return rev;
}

int main() {
    int x;
    cout << "Enter number: ";
    cin >> x;

    cout << "Reversed Integer: " << reverse(x) << endl;

    return 0;
}
