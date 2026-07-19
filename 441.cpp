#include <iostream>
using namespace std;

int arrangeCoins(int n) {
    long long left = 0, right = n;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long coins = mid * (mid + 1) / 2;

        if (coins == n)
            return mid;
        else if (coins < n)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return right;
}

int main() {
    int n;
    cout << "Enter number of coins: ";
    cin >> n;

    cout << "Complete rows: " << arrangeCoins(n) << endl;

    return 0;
}
