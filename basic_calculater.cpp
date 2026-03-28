#include <iostream>
#include <stack>
#include <string>
using namespace std;

int calculate(string s) {
    stack<int> st;
    int result = 0;
    int number = 0;
    int sign = 1;

    for (int i = 0; i < s.length(); i++) {

        if (isdigit(s[i])) {
            number = number * 10 + (s[i] - '0');
        }

        else if (s[i] == '+') {
            result += sign * number;
            number = 0;
            sign = 1;
        }

        else if (s[i] == '-') {
            result += sign * number;
            number = 0;
            sign = -1;
        }

        else if (s[i] == '(') {
            st.push(result);
            st.push(sign);

            result = 0;
            sign = 1;
        }

        else if (s[i] == ')') {
            result += sign * number;
            number = 0;

            result *= st.top();
            st.pop();

            result += st.top();
            st.pop();
        }
    }

    result += sign * number;
    return result;
}

int main() {
    string s;

    cout << "Enter expression: ";
    getline(cin, s);

    cout << "Result = " << calculate(s) << endl;

    return 0;
}