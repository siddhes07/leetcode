#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to store: {sorted_string : list_of_anagrams}
        unordered_map<string, vector<string>> anagramMap;

        for (string s : strs) {
            string sorted_s = s;
            // Sort the string to use as a unique key
            sort(sorted_s.begin(), sorted_s.end());
            
            // Push the original string into the vector corresponding to its sorted key
            anagramMap[sorted_s].push_back(s);
        }

        // Prepare the result by extracting values from the map
        vector<vector<string>> result;
        for (auto const& [key, val] : anagramMap) {
            result.push_back(val);
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    // Test input
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    // Get grouped anagrams
    vector<vector<string>> grouped = sol.groupAnagrams(input);

    // Print the results
    cout << "Grouped Anagrams:" << endl;
    for (const auto& group : grouped) {
        cout << "[ ";
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}