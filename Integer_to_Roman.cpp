#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<int> values = {
            1000, 900, 500, 400,
            100, 90, 50, 40,
            10, 9, 5, 4, 1
        };
        
        vector<string> symbols = {
            "M", "CM", "D", "CD",
            "C", "XC", "L", "XL",
            "X", "IX", "V", "IV", "I"
        };
        
        string result = "";
        
        for (int i = 0; i < values.size(); i++) {
            while (num >= values[i]) {
                result += symbols[i];
                num -= values[i];
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    int num;
    cout << "Enter a number (1 - 3999): ";
    cin >> num;
    
    if (num < 1 || num > 3999) {
        cout << "Number out of range!" << endl;
        return 0;
    }
    
    string roman = sol.intToRoman(num);
    cout << "Roman numeral: " << roman << endl;
    
    return 0;
}