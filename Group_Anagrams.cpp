#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Key: sorted version of the word
        // Value: list of original words that are anagrams of each other
        unordered_map<string, vector<string>> mp;

        for (const string& word : strs) {
            string key = word;
            sort(key.begin(), key.end()); // e.g. "eat" -> "aet"
            mp[key].push_back(word);
        }

        // Collect all groups into result
        vector<vector<string>> result;
        for (auto& [key, group] : mp) {
            result.push_back(group);
        }

        return result;
    }
};

// Helper: print groups
void printGroups(const vector<vector<string>>& groups) {
    cout << "[" << endl;
    for (const auto& group : groups) {
        cout << "  [ ";
        for (const string& s : group) cout << "\"" << s << "\" ";
        cout << "]" << endl;
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // ------- Test Case 1 -------
    // Expected: [["bat"],["nat","tan"],["ate","eat","tea"]] (order may vary)
    vector<string> strs1 = {"eat","tea","tan","ate","nat","bat"};
    cout << "Test 1: [\"eat\",\"tea\",\"tan\",\"ate\",\"nat\",\"bat\"]" << endl;
    cout << "Grouped Anagrams:" << endl;
    printGroups(sol.groupAnagrams(strs1));
    cout << endl;

    // ------- Test Case 2 -------
    // Expected: [[""]]
    vector<string> strs2 = {""};
    cout << "Test 2: [\"\"]" << endl;
    cout << "Grouped Anagrams:" << endl;
    printGroups(sol.groupAnagrams(strs2));
    cout << endl;

    // ------- Test Case 3 -------
    // Expected: [["a"]]
    vector<string> strs3 = {"a"};
    cout << "Test 3: [\"a\"]" << endl;
    cout << "Grouped Anagrams:" << endl;
    printGroups(sol.groupAnagrams(strs3));
    cout << endl;

    // ------- Test Case 4 -------
    // All same anagram group
    vector<string> strs4 = {"abc","bca","cab","cba","bac","acb"};
    cout << "Test 4: [\"abc\",\"bca\",\"cab\",\"cba\",\"bac\",\"acb\"]" << endl;
    cout << "Grouped Anagrams:" << endl;
    printGroups(sol.groupAnagrams(strs4));
    cout << endl;

    // ------- Test Case 5 -------
    // No anagrams — all separate groups
    vector<string> strs5 = {"cat","dog","bird"};
    cout << "Test 5: [\"cat\",\"dog\",\"bird\"]" << endl;
    cout << "Grouped Anagrams:" << endl;
    printGroups(sol.groupAnagrams(strs5));

    return 0;
}