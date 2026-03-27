#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {

    string prefix = strs[0];

    for(int i = 1; i < strs.size(); i++) {

        while(strs[i].find(prefix) != 0) {

            prefix = prefix.substr(0, prefix.length() - 1);

            if(prefix == "")
                return "";
        }
    }

    return prefix;
}

int main() {

    vector<string> strs = {"flower", "flow", "flight"};

    string result = longestCommonPrefix(strs);

    cout << "Longest Common Prefix is: " << result;

    return 0;
}