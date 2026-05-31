#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int m = img.size(), n = img[0].size();
    vector<vector<int>> ans(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0, cnt = 0;

            for (int x = i - 1; x <= i + 1; x++) {
                for (int y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < m && y >= 0 && y < n) {
                        sum += img[x][y];
                        cnt++;
                    }
                }
            }

            ans[i][j] = sum / cnt;
        }
    }
    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> img(m, vector<int>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> img[i][j];

    vector<vector<int>> result = imageSmoother(img);

    for (auto &row : result) {
        for (int x : row)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}
