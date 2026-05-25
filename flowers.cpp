#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int count = 0;

        for (int i = 0; i < size; i++) {
            // Check if current plot is empty
            if (flowerbed[i] == 0) {
                bool leftEmpty  = (i == 0) || (flowerbed[i - 1] == 0);
                bool rightEmpty = (i == size - 1) || (flowerbed[i + 1] == 0);

                if (leftEmpty && rightEmpty) {
                    flowerbed[i] = 1; // Place flower
                    count++;
                }
            }
        }

        return count >= n;
    }
};

int main() {
    Solution sol;

    // Test Case 1: Expected -> true
    vector<int> flowerbed1 = {1, 0, 0, 0, 1};
    int n1 = 1;
    cout << "Test 1: " << (sol.canPlaceFlowers(flowerbed1, n1) ? "true" : "false") << endl;

    // Test Case 2: Expected -> false
    vector<int> flowerbed2 = {1, 0, 0, 0, 1};
    int n2 = 2;
    cout << "Test 2: " << (sol.canPlaceFlowers(flowerbed2, n2) ? "true" : "false") << endl;

    // Test Case 3: Expected -> true (empty bed)
    vector<int> flowerbed3 = {0, 0, 0, 0, 0};
    int n3 = 3;
    cout << "Test 3: " << (sol.canPlaceFlowers(flowerbed3, n3) ? "true" : "false") << endl;

    // Test Case 4: Expected -> true (single plot)
    vector<int> flowerbed4 = {0};
    int n4 = 1;
    cout << "Test 4: " << (sol.canPlaceFlowers(flowerbed4, n4) ? "true" : "false") << endl;

    return 0;
}