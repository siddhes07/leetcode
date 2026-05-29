#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string& token : tokens) {
            if (token == "+" || token == "-" || 
                token == "*" || token == "/") {
                
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if (token == "+") st.push(a + b);
                if (token == "-") st.push(a - b);
                if (token == "*") st.push(a * b);
                if (token == "/") st.push(a / b);
            } 
            else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

int main() {
    Solution sol;

    int n;
    cout << "किती tokens आहेत ते सांग: ";
    cin >> n;

    vector<string> tokens(n);
    cout << "Tokens एक एक करून टाक: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Token " << i + 1 << ": ";
        cin >> tokens[i];
    }

    cout << "\nAnswer: " << sol.evalRPN(tokens) << endl;

    return 0;
}