// Question: https://leetcode.com/problems/unique-binary-search-trees/

#include "headers.h"

class Solution {
public:
    int numTrees(int n) {
        if (n == 1 || n == 0) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        if (memo.count(n) > 0) {
            return memo[n];
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += numTrees(i-1) * numTrees(n-i);
        }

        memo[n] = ans;
        return ans;
    }

private:
    unordered_map<int, int> memo;
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.numTrees(19);
}
