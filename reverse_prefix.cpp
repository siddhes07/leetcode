#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string word;
    char ch;

    cout << "Enter word: ";
    cin >> word;

    cout << "Enter character: ";
    cin >> ch;

    int index = word.find(ch);

    if (index != -1) {
        reverse(word.begin(), word.begin() + index + 1);
    }

    cout << "Result: " << word << endl;

    return 0;
}