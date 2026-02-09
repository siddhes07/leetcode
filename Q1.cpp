#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "Enter first number: ";
    cin >> a;

    cout << "Enter second number: ";
    cin >> b;

    cout << "Sum = " << a + b << endl;
    cout << "Difference = " << a - b << endl;
    cout << "Product = " << a * b << endl;

    if (b != 0) {
        cout << "Division = " << a / b << endl;
    } else {
        cout << "Division not possible" << endl;
    }

    return 0;
}
