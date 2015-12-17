// Question: https://leetcode.com/problems/bitwise-and-of-numbers-range/

#include "headers.h"

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int diff_bits = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++diff_bits;
        }
        return n << diff_bits;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.rangeBitwiseAnd(5, 7) << endl;
    return 0;
}
