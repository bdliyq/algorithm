// Question: https://leetcode.com/problems/ugly-number-ii/

#include "headers.h"

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n, 1);
        int i = 0, j = 0, k = 0;
        for (int idx = 1; idx <= n-1; ++idx) {
            ans[idx] = min(ans[i]*2, min(ans[j]*3, ans[k]*5));
            if (ans[idx] % 2 == 0) { ++i; }
            if (ans[idx] % 3 == 0) { ++j; }
            if (ans[idx] % 5 == 0) { ++k; }
        }
        return ans[n-1];
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.nthUglyNumber(11) << endl;
    return 0;
}
