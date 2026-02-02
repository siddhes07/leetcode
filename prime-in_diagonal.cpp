#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1)
        return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;

    int a[n][n];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Prime numbers on diagonal: ";
    for (int i = 0; i < n; i++) {
        if (isPrime(a[i][i])) {
            cout << a[i][i] << " ";
        }
    }

    return 0;
}
