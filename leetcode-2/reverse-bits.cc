// Question: class Solution {
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
