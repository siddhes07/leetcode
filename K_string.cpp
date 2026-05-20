#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.length();

        // If k is greater than string length
        if (k > n) {
            return 0;
        }

        unordered_map<char, int> freq;

        // First window
        for (int i = 0; i < k; i++) {
            freq[s[i]]++;
        }

        int count = 0;

        // Check first window
        if (freq.size() == k) {
            count++;
        }

        // Sliding window
        for (int i = k; i < n; i++) {

            // Add new character
            freq[s[i]]++;

            // Remove old character
            freq[s[i - k]]--;

            // Remove from map if frequency becomes 0
            if (freq[s[i - k]] == 0) {
                freq.erase(s[i - k]);
            }

            // If all characters are unique
            if (freq.size() == k) {
                count++;
            }
        }

        return count;
    }
};

int main() {
    Solution obj;

    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    int ans = obj.numKLenSubstrNoRepeats(s, k);

    cout << "Answer = " << ans << endl;

    return 0;
}
