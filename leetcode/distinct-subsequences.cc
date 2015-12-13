// Question: https://leetcode.com/problems/distinct-subsequences/

#include "headers.h"

class Solution {
public:
    int numDistinct(string s, string t) {
        int len = t.size();
        vector<int> dp(len+1, 0);
        dp[0] = 1;
        for (auto c : s) {
            for (int i = len-1; i >= 0; --i) {
                if (c == t[i]) {
                    dp[i+1] = dp[i] + dp[i+1];
                }
            }
        }
        return dp.back();
    }
};

int main(int argc, char** argv) {
    Solution s;
    cout << s.numDistinct("rabbbit", "rabbit") << endl;
    return 0;
}
