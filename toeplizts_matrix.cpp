#include <iostream>
using namespace std;

// Function 1: Check whether matrix is Toeplitz
bool isToeplitz(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < cols - 1; j++) {
            if (mat[i][j] != mat[i + 1][j + 1])
                return false;
        }
    }
    return true;
}

// Function 2: Display matrix
void displayMatrix(int mat[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int mat[10][10] = {
        {1, 2, 3},
        {4, 1, 2},
        {5, 4, 1}
    };

    int rows = 3, cols = 3;

    cout << "Matrix:" << endl;
    displayMatrix(mat, rows, cols);

    if (isToeplitz(mat, rows, cols))
        cout << "Matrix is Toeplitz" << endl;
    else
        cout << "Matrix is NOT Toeplitz" << endl;

    return 0;
}
