#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;

    string haystack = "sadbutsad";
    string needle = "sad";

    cout << sol.strStr(haystack, needle) << endl;

    return 0;
}