#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> result;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            result.push_back(node);

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        if (result.size() == numCourses)
            return result;

        return {};
    }
};

int main() {
    Solution sol;

    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    vector<int> order = sol.findOrder(numCourses, prerequisites);

    if (order.empty()) {
        cout << "No valid course order exists." << endl;
    } else {
        cout << "Course Order: ";
        for (int course : order)
            cout << course << " ";
        cout << endl;
    }

    return 0;
}