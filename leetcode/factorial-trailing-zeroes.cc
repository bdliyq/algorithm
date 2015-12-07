// Question: https://leetcode.com/problems/factorial-trailing-zeroes/

#include "headers.h"

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while (n > 0) {
            int x = n/5;
            ans += x;
            n = x;
        }
        return ans;
    }
};
