#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        
        // Hash maps — किती lamps आहेत त्या row/col/diagonal वर
        unordered_map<int, int> rowCount, colCount, diagCount, antiDiagCount;
        
        // Active lamps set (duplicate avoid करायला)
        // Key: row * (n+1) + col  (unique encoding)
        unordered_set<long long> lampSet;

        // सगळे lamps register करा
        for (auto& lamp : lamps) {
            int r = lamp[0], c = lamp[1];
            long long key = (long long)r * (n + 1) + c;

            if (lampSet.count(key)) continue; // duplicate lamp skip
            lampSet.insert(key);

            rowCount[r]++;
            colCount[c]++;
            diagCount[r - c]++;        // Main diagonal: r-c constant असतो
            antiDiagCount[r + c]++;   // Anti diagonal: r+c constant असतो
        }

        vector<int> ans;

        // 8 neighbours + खुद cell (3x3 block)
        int dirs[9][2] = {
            {-1,-1},{-1,0},{-1,1},
            { 0,-1},{ 0,0},{ 0,1},
            { 1,-1},{ 1,0},{ 1,1}
        };

        for (auto& query : queries) {
            int qr = query[0], qc = query[1];

            // Cell illuminate आहे का?
            if (rowCount[qr] > 0 || colCount[qc] > 0 ||
                diagCount[qr - qc] > 0 || antiDiagCount[qr + qc] > 0) {
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }

            // 3x3 neighbourhood मधले lamps turn off करा
            for (auto& d : dirs) {
                int nr = qr + d[0];
                int nc = qc + d[1];

                // Grid boundary check
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                long long key = (long long)nr * (n + 1) + nc;

                if (lampSet.count(key)) {
                    lampSet.erase(key);
                    rowCount[nr]--;
                    colCount[nc]--;
                    diagCount[nr - nc]--;
                    antiDiagCount[nr + nc]--;
                }
            }
        }

        return ans;
    }
};

// ──────────────────────────────────────
int main() {
    Solution sol;

    // Example 1
    int n1 = 5;
    vector<vector<int>> lamps1 = {{0,0},{4,4}};
    vector<vector<int>> queries1 = {{1,1},{1,0}};

    vector<int> result1 = sol.gridIllumination(n1, lamps1, queries1);

    cout << "Example 1 Output: [";
    for (int i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i + 1 < result1.size()) cout << ", ";
    }
    cout << "]" << endl;
    // Expected: [1, 0]

    // Example 2
    int n2 = 5;
    vector<vector<int>> lamps2 = {{0,0},{4,4}};
    vector<vector<int>> queries2 = {{1,1},{1,1}};

    vector<int> result2 = sol.gridIllumination(n2, lamps2, queries2);

    cout << "Example 2 Output: [";
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i + 1 < result2.size()) cout << ", ";
    }
    cout << "]" << endl;
    // Expected: [1, 1]

    // Example 3 — Custom
    int n3 = 5;
    vector<vector<int>> lamps3 = {{0,0},{2,2},{4,4}};
    vector<vector<int>> queries3 = {{2,2},{0,0},{3,3}};

    vector<int> result3 = sol.gridIllumination(n3, lamps3, queries3);

    cout << "Example 3 Output: [";
    for (int i = 0; i < result3.size(); i++) {
        cout << result3[i];
        if (i + 1 < result3.size()) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}