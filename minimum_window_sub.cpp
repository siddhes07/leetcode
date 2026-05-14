#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        // Frequency map for characters needed from t
        unordered_map<char, int> need;
        for (char c : t) need[c]++;

        int required = need.size(); // number of unique chars in t to satisfy
        int formed  = 0;            // unique chars in current window with desired freq

        unordered_map<char, int> window;

        int left = 0, right = 0;
        int minLen = INT_MAX, minLeft = 0;

        while (right < (int)s.size()) {
            // Expand window to the right
            char c = s[right++];
            window[c]++;

            // Check if current char satisfies the required frequency
            if (need.count(c) && window[c] == need[c])
                formed++;

            // Try to shrink window from the left while it's valid
            while (left < right && formed == required) {
                // Update result if this window is smaller
                if (right - left < minLen) {
                    minLen  = right - left;
                    minLeft = left;
                }

                // Remove leftmost char and shrink
                char lc = s[left++];
                window[lc]--;
                if (need.count(lc) && window[lc] < need[lc])
                    formed--;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};

int main() {
    Solution sol;

    // Test cases
    struct TestCase {
        string s, t, expected;
    };

    TestCase tests[] = {
        {"ADOBECODEBANC", "ABC", "BANC"},
        {"a",            "a",   "a"  },
        {"a",            "aa",  ""   },
        {"aa",           "aa",  "aa" },
        {"cabwefgewcwaefgcf", "cae", "cwae"},
    };

    int passed = 0, total = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < total; i++) {
        string result = sol.minWindow(tests[i].s, tests[i].t);
        bool ok = (result == tests[i].expected);
        if (ok) passed++;

        cout << "Test " << i + 1 << ": "
             << "s=\"" << tests[i].s << "\", t=\"" << tests[i].t << "\"\n"
             << "  Expected : \"" << tests[i].expected << "\"\n"
             << "  Got      : \"" << result << "\"\n"
             << "  Status   : " << (ok ? "PASSED" : "FAILED") << "\n\n";
    }

    cout << "Result: " << passed << "/" << total << " tests passed.\n";
    return 0;
}