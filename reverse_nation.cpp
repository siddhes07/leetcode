#include <iostream>
#include <algorithm>
using namespace std;

string reversePrefix(string word, char ch) {
    int idx = -1;

    // find first occurrence of ch
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == ch) {
            idx = i;
            break;
        }
    }

    // if found, reverse from 0 to idx
    if (idx != -1) {
        reverse(word.begin(), word.begin() + idx + 1);
    }

    return word;
}

int main() {
    string word;
    char ch;

    cout << "Enter word: ";
    cin >> word;

    cout << "Enter character: ";
    cin >> ch;

    string result = reversePrefix(word, ch);

    cout << "Result: " << result << endl;

    return 0;
} 