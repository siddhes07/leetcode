#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int idx = word.find(ch);

        if (idx == string::npos)
            return word;

        reverse(word.begin(), word.begin() + idx + 1);
        return word;
    }
};

int main() {
    Solution obj;

    string word = "abcdefd";
    char ch = 'd';

    cout << obj.reversePrefix(word, ch) << endl;

    return 0;
}