// Question: https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) {
            return 0;
        }
        int l = 1, r = x;
        while (l <= r) {
            int m = l + (r-l)/2;
            int t = x/m;
            if (t == m) {
                return m;
            } else if (t > m) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
};
