// Question: https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string str) {
        long ans = 0l;
        int i = 0;
        int len = str.size();
        bool negative = false;
        while (i < len && str[i] == ' ') {
            ++i;
        }
        if (i < len && (str[i] == '+' || str[i] == '-')) {
            if (str[i] == '-') {
                negative = true;
            }
            ++i;
        }
        while (i < len && str[i] >= '0' && str[i] <= '9') {
            ans = ans * 10 + str[i] - '0';
            ++i;
            if (negative) {
                if (-ans < INT_MIN) {
                    return INT_MIN;
                }
            } else {
                if (ans > INT_MAX) {
                    return INT_MAX;
                }
            }
        }
        return negative ? -ans : ans;
    }
};
