// Question: https://leetcode.com/problems/reverse-integer/

#include "headers.h"

class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        int sign = 1;
        if (abs(x) != x) {
            sign = -1;
        }

        x = abs(x);
        while (x > 0) {
            ans = ans * 10 + x % 10;
            if (ans * sign >= INT_MAX || ans * sign <= INT_MIN) {
                return 0;
            }
            x /= 10;
        }

        return ans * sign;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.reverse(-123) << endl;
    cout << s.reverse(-100) << endl;
}
