#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string build(string s) {
        string res;

        for (char c : s) {
            if (c != '#') {
                res.push_back(c);
            } else if (!res.empty()) {
                res.pop_back();
            }
        }

        return res;
    }

    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
};

int main() {
    Solution sol;

    string s = "ab#c";
    string t = "ad#c";

    if (sol.backspaceCompare(s, t))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}