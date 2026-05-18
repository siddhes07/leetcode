#include <iostream>
using namespace std;

string freqAlphabets(string s) {
    string ans = "";

    for (int i = 0; i < s.length(); i++) {

        // Check if next 2 characters form a number with #
        if (i + 2 < s.length() && s[i + 2] == '#') {

            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

            ans += char('a' + num - 1);

            i += 2; // Skip next two characters
        }
        else {

            int num = s[i] - '0';

            ans += char('a' + num - 1);
        }
    }

    return ans;
}

int main() {

    string s;

    cout << "Enter encoded string: ";
    cin >> s;

    string result = freqAlphabets(s);

    cout << "Decoded string: " << result;

    return 0;
}
