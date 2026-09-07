class Solution {
public:
    bool isNumber(string s) {
        bool digit = false;
        bool dot = false;
        bool exp = false;
        bool expDigit = true;

        for (int i = 0; i < s.length(); i++) {

            char c = s[i];

            // Digit
            if (isdigit(c)) {
                digit = true;

                if (exp)
                    expDigit = true;
            }

            // Decimal point
            else if (c == '.') {
                if (dot || exp)
                    return false;

                dot = true;
            }

            // Exponent
            else if (c == 'e' || c == 'E') {
                if (exp || !digit)
                    return false;

                exp = true;
                expDigit = false;
            }

            // Sign
            else if (c == '+' || c == '-') {
                if (i != 0 &&
                    s[i - 1] != 'e' &&
                    s[i - 1] != 'E')
                    return false;
            }

            // Anything else
            else {
                return false;
            }
        }

        return digit && expDigit;
    }
};
