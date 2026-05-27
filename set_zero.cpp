#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> row(rows, 0);
        vector<int> col(cols, 0);

        // find zeros
        for(int i = 0; i < rows; i++) {

            for(int j = 0; j < cols; j++) {

                if(matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // set rows and cols to zero
        for(int i = 0; i < rows; i++) {

            for(int j = 0; j < cols; j++) {

                if(row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

int main() {

    vector<vector<int>> matrix = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    Solution obj;
    obj.setZeroes(matrix);

    // print matrix
    for(int i = 0; i < matrix.size(); i++) {

        for(int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}