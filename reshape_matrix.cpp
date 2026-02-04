#include <iostream>
using namespace std;

// Function to reshape matrix
void reshapeMatrix(int mat[10][10], int r, int c, int newR, int newC) {
    // Check if reshape is possible
    if (r * c != newR * newC) {
        cout << "Reshape not possible" << endl;
        return;
    }

    int temp[100];
    int k = 0;

    // Store elements in 1D array
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            temp[k++] = mat[i][j];
        }
    }

    // Print reshaped matrix
    k = 0;
    for (int i = 0; i < newR; i++) {
        for (int j = 0; j < newC; j++) {
            cout << temp[k++] << " ";
        }
        cout << endl;
    }
}

int main() {
    int mat[10][10];
    int r, c, newR, newC;

    cout << "Enter rows and columns of matrix: ";
    cin >> r >> c;

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Enter new rows and columns: ";
    cin >> newR >> newC;

    reshapeMatrix(mat, r, c, newR, newC);

    return 0;
}
