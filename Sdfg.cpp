#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();

        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> indegree;

        for (auto &seq : sequences) {
            for (int num : seq) {
                indegree[num];
            }

            for (int i = 1; i < seq.size(); i++) {
                graph[seq[i - 1]].push_back(seq[i]);
                indegree[seq[i]]++;
            }
        }

        if (indegree.size() != n)
            return false;

        queue<int> q;
        for (auto &p : indegree) {
            if (p.second == 0)
                q.push(p.first);
        }

        vector<int> result;

        while (!q.empty()) {
            if (q.size() > 1)
                return false; // Multiple choices => not unique

            int node = q.front();
            q.pop();

            result.push_back(node);

            for (int nei : graph[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        return result == nums;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> sequences = {{1, 2}, {1, 3}, {2, 3}};

    cout << (obj.sequenceReconstruction(nums, sequences) ? "true" : "false") << endl;

    return 0;
}
