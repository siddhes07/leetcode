#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for(char c : s) {
        st.push(c);

        // Check last three characters
        if(st.size() >= 3) {
            char c1 = st.top(); st.pop();
            char c2 = st.top(); st.pop();
            char c3 = st.top(); st.pop();

            if(c3 == 'a' && c2 == 'b' && c1 == 'c') {
                // valid pattern "abc", do nothing
            } else {
                // put back if not "abc"
                st.push(c3);
                st.push(c2);
                st.push(c1);
            }
        }
    }

    return st.empty();
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    if(isValid(s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}