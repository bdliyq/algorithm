// Question: https://leetcode.com/problems/string-to-integer-atoi/

#include "headers.h"

class Solution {
public:
    int myAtoi(string str) {
        long long ans = 0;
        int len = str.size();
        int i = 0;
        int sign = 1;
        while (i < len && str[i] == ' ') {
            ++i;
        }
        if (i < len && (str[i] == '+' || str[i] == '-')) {
            if (str[i] == '-') {
                sign = -1;
            }
            ++i;
        }
        int flag = 0;
        while (i < len && isdigit(str[i])) {
            ans = ans * 10 + str[i] - '0';
            if (ans * sign >= INT_MAX || ans * sign <= INT_MIN) {
                if (sign == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            ++i;
        }

        return sign * ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.myAtoi("-2147483647") << endl;
    cout << s.myAtoi("2147483648") << endl;
    // cout << s.myAtoi("-123") << endl;
    // cout << s.myAtoi("123") << endl;
    // cout << s.myAtoi("0") << endl;
    // cout << s.myAtoi("999999999999") << endl;
    // cout << s.myAtoi("-999999999999") << endl;
}
