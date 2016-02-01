// Question: https://leetcode.com/problems/divide-two-integers/

#include "headers.h"

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            sign = -1;
        }
        long abs_dividend = abs((long)dividend);
        long abs_divisor = abs((long)divisor);
        long ans = 0;
        while (abs_dividend >= abs_divisor) {
            long cnt = 1;
            long tmp = abs_divisor;
            while (tmp <= abs_dividend) {
                cnt <<= 1;
                tmp <<= 1;
            }
            cnt >>= 1;
            tmp >>= 1;
            ans += cnt;
            abs_dividend -= tmp;
        }

        if (sign == -1) {
            return (int)sign * ans;
        } else {
            if (ans > INT_MAX) {
                return INT_MAX;
            } else {
                return (int)ans;
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.divide(1, 3) << endl;
    cout << s.divide(4, 3) << endl;
    return 0;
}
