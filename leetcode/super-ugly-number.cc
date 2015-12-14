// Question: https://leetcode.com/problems/super-ugly-number/

#include "headers.h"

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ans{1};
        vector<int> idx(primes.size(), 0);
        for (int i = 1; i < n; ++i) {
            int t = INT_MAX;
            for (int j = 0; j < primes.size(); ++j) {
                t = min(t, ans[idx[j]] * primes[j]);
            }
            for (int j = 0; j < primes.size(); ++j) {
                if (t % primes[j] == 0) {
                    ++idx[j];
                }
            }
            ans.push_back(t);
        }
        return ans.back();
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> primes{2, 7, 13, 19};
    cout << s.nthSuperUglyNumber(12, primes) << endl;
    return 0;
}
