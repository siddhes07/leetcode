#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        
        string prefix = strs[0];
        
        for(int i = 1; i < strs.size(); i++) {
            while(strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                
                if(prefix.empty())
                    return "";
            }
        }
        return prefix;
    }
};

int main() {
    Solution obj;
    
    vector<string> strs = {"flower", "flow", "flight"};
    
    string result = obj.longestCommonPrefix(strs);
    
    cout << "Longest Common Prefix: " << result << endl;
    
    return 0;
}
