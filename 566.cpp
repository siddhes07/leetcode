#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int m = mat.size(), n = mat[0].size();

    if (m * n != r * c)
        return mat;

    vector<vector<int>> res(r, vector<int>(c));

    for (int i = 0; i < m * n; i++) {
        res[i / c][i % c] = mat[i / n][i % n];
    }

    return res;
}

int main() {
    int m, n;
    cout << "Rows ani Columns ghala (m n): ";
    cin >> m >> n;

    vector<vector<int>> mat(m, vector<int>(n));
    cout << "Matrix ghala:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    int r, c;
    cout << "Nava shape ghala (r c): ";
    cin >> r >> c;

    vector<vector<int>> result = matrixReshape(mat, r, c);

    cout << "Result:\n";
    for (auto& row : result) {
        for (int val : row)
            cout << val << " ";
        cout << "\n";
    }

    return 0;
}