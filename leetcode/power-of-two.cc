// Question: https://leetcode.com/problems/power-of-two/

#include "headers.h"

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }
        int cnt = 0;
        while (n) {
            if (n & 0x1) {
                ++cnt;
            }
            if (cnt > 1) {
                return false;
            }
            n >>= 1;
        }
        return true;
    }
};
