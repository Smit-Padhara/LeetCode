#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1, result = 0;

        // Step 1: Skip leading whitespaces
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Step 2: Handle optional sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Step 4: Check for overflow
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};
