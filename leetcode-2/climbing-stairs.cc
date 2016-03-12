// Question: https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2) {
            return n;
        }

        int i = 1, j = 2;
        for (int k = 3; k <= n; ++k) {
            int r = i+j;
            i = j;
            j = r;
        }
        return j;
    }
};
