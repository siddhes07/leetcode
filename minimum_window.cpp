#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        // t madhlya characters cha count store karnyasathi
        unordered_map<char, int> targetCount;
        for (char c : t) targetCount[c]++;

        unordered_map<char, int> windowCount;
        int left = 0, right = 0;
        int required = targetCount.size(); // Kiti unique characters pahije
        int formed = 0; // Current window madhe kiti complete jhale ahet

        int minLen = INT_MAX;
        int startIdx = 0;

        while (right < s.length()) {
            char c = s[right];
            windowCount[c]++;

            // Jar current character cha count target shi match jhala
            if (targetCount.count(c) && windowCount[c] == targetCount[c]) {
                formed++;
            }

            // Window shrink karnyao prayatna kara (jar sagle characters bhetle astil tar)
            while (left <= right && formed == required) {
                c = s[left];

                // Update minimum window length
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                // Left pointer pudhe sarka ani window size kami kara
                windowCount[c]--;
                if (targetCount.count(c) && windowCount[c] < targetCount[c]) {
                    formed--;
                }
                left++;
            }
            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};

// Main function testing sathi
int main() {
    Solution sol;
    string s = "ADOBECODEBANC";
    string t = "ABC";

    string result = sol.minWindow(s, t);

    cout << "Input S: " << s << ", T: " << t << endl;
    cout << "Minimum Window Substring: " << result << endl;

    return 0;
}