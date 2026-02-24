#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;

    cout << "Enter number of variables: ";
    cin >> n;

    double a[n][n+1], x[n];

    cout << "Enter coefficients of augmented matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    // Forward Elimination
    for(int i = 0; i < n - 1; i++) {
        for(int k = i + 1; k < n; k++) {
            if(a[i][i] == 0.0) {
                cout << "Mathematical Error!";
                return 0;
            }

            double factor = a[k][i] / a[i][i];

            for(int j = i; j <= n; j++) {
                a[k][j] = a[k][j] - factor * a[i][j];
            }
        }
    }

    // Back Substitution
    for(int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];

        for(int j = i + 1; j < n; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }

        x[i] = x[i] / a[i][i];
    }

    cout << "\nSolution:\n";
    for(int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
