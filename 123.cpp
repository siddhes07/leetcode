#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int balancedString(string s) {
        int n = s.length();
        unordered_map<char, int> count;

        // Count frequency of each character
        for (char c : s) {
            count[c]++;
        }

        int required = n / 4;
        int left = 0;
        int minLen = n;

        for (int right = 0; right < n; right++) {
            count[s[right]]--;

            while (left < n &&
                   count['Q'] <= required &&
                   count['W'] <= required &&
                   count['E'] <= required &&
                   count['R'] <= required) {

                minLen = min(minLen, right - left + 1);
                count[s[left]]++;
                left++;
            }
        }

        return minLen;
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter string (only QWER): ";
    cin >> s;

    int result = sol.balancedString(s);

    cout << "Minimum substring length to replace: " << result << endl;

    return 0;
}