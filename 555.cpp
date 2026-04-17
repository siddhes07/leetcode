#include <bits/stdc++.h>
using namespace std;

string splitLoopedString(vector<string>& strs) {
    int n = strs.size();

    // Step 1: Make each string lexicographically larger by reversing if needed
    for (int i = 0; i < n; i++) {
        string rev = strs[i];
        reverse(rev.begin(), rev.end());
        if (rev > strs[i]) {
            strs[i] = rev;
        }
    }

    string result = "";

    // Step 2: Try every string as starting point
    for (int i = 0; i < n; i++) {
        string current = strs[i];
        string rev = current;
        reverse(rev.begin(), rev.end());

        // Try both original and reversed version
        for (string s : {current, rev}) {
            for (int k = 0; k < s.size(); k++) {
                string temp = s.substr(k);

                // add next strings
                for (int j = i + 1; j < n; j++) temp += strs[j];
                for (int j = 0; j < i; j++) temp += strs[j];

                // add remaining part of current string
                temp += s.substr(0, k);

                result = max(result, temp);
            }
        }
    }

    return result;
}

int main() {
    vector<string> strs = {"abc", "xyz"};
    
    string ans = splitLoopedString(strs);
    
    cout << "Result: " << ans << endl;
    
    return 0;
}
