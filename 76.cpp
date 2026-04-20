#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    if (s.size() < t.size()) return "";

    unordered_map<char, int> freq;
    for (char c : t) {
        freq[c]++;
    }

    int left = 0, right = 0;
    int required = t.size();
    int minLen = INT_MAX;
    int start = 0;

    while (right < s.size()) {
        if (freq[s[right]] > 0) {
            required--;
        }
        freq[s[right]]--;
        right++;

        while (required == 0) {
            if (right - left < minLen) {
                minLen = right - left;
                start = left;
            }

            freq[s[left]]++;
            if (freq[s[left]] > 0) {
                required++;
            }
            left++;
        }
    }

    return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
}

int main() {
    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    string result = minWindow(s, t);

    if (result == "") {
        cout << "No valid window found." << endl;
    } else {
        cout << "Minimum window substring: " << result << endl;
    }

    return 0;
}