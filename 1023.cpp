#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> stones = {a, b, c};
        sort(stones.begin(), stones.end());

        a = stones[0];
        b = stones[1];
        c = stones[2];

        int minMoves;

        if (c - a == 2)
            minMoves = 0;
        else if (b - a <= 2 || c - b <= 2)
            minMoves = 1;
        else
            minMoves = 2;

        int maxMoves = (b - a - 1) + (c - b - 1);

        return {minMoves, maxMoves};
    }
};

int main() {
    Solution sol;

    int a = 1, b = 2, c = 5;

    vector<int> ans = sol.numMovesStones(a, b, c);

    cout << "Minimum Moves = " << ans[0] << endl;
    cout << "Maximum Moves = " << ans[1] << endl;

    return 0;
}