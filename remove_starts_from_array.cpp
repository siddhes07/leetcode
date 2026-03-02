#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cout << "Enter a string: ";
    cin>>s;

    string result = "";

    for (char ch : s) {
        if (ch == '*') {
            if (!result.empty()) {
                result.pop_back();  // remove left character
            }
        }
        else {
            result += ch;  // add normal character
        }
    }

    cout << "Final string: " << result << endl;

    return 0;
}
