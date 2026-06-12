#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp = a;
        int count = 1;

        while (temp.size() < b.size()) {
            temp += a;
            count++;
        }

        if (temp.find(b) != string::npos)
            return count;

        temp += a;
        count++;

        if (temp.find(b) != string::npos)
            return count;

        return -1;
    }
};

int main() {
    Solution obj;

    string a, b;

    cout << "Enter string a: ";
    cin >> a;

    cout << "Enter string b: ";
    cin >> b;

    cout << "Output: " << obj.repeatedStringMatch(a, b) << endl;

    return 0;
}