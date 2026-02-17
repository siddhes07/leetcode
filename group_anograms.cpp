// group_anagrams.cpp

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());  // Sort characters to form key
        mp[key].push_back(s);
    }

    vector<vector<string>> result;
    for (auto& pair : mp) {
        result.push_back(pair.second);
    }

    return result;
}

int main() {
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};

    vector<vector<string>> grouped = groupAnagrams(input);

    cout << "Grouped Anagrams:\n";
    for (const auto& group : grouped) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}
