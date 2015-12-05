// Question: https://leetcode.com/problems/climbing-stairs/

#include "headers.h"

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int i = 1;
        int j = 2;

        for (int x = 2; x < n; ++x) {
            int r = i + j;
            i = j;
            j = r;
        }

        return j;
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.climbStairs(4) << endl;
    return 0;
}
