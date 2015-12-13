// Question: https://leetcode.com/problems/sqrtx/

#include "headers.h"

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0) {
            return 0;
        }

        int i = 1, j = x;
        while (i+1 < j) {
            int m = i + (j - i) / 2;
            int t = x / m;
            if (m == t) {
                return m;
            } else if (t > m) {
                i = m;
            } else {
                j = m;
            }
        }

        return i;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.mySqrt(2147395599) << endl;
    return 0;
}
