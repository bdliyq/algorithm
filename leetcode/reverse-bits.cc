// Question: https://leetcode.com/problems/reverse-bits/

#include "headers.h"

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            ans <<= 1;
            ans |= (n >> i) & 0x1;
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.reverseBits(43261596) << endl;
    return 0;
}
