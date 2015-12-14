// Question: https://leetcode.com/problems/number-of-1-bits/

#include "headers.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            if ((n >> i) & 0x1) {
                ++ans;
            }
        }
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.hammingWeight(11) << endl;
    return 0;
}
