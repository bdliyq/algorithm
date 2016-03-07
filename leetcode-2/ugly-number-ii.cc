// Question: https://leetcode.com/problems/ugly-number-ii/

class Solution {
public:
    int nthUglyNumber(int n) {
        int i = 0, j = 0, k = 0;

        vector<int> ans{1};
        for (int m = 1; m < n; ++m) {
            ans.push_back(min(min(ans[i]*2, ans[j]*3), ans[k]*5));
            if (ans.back() % 2 == 0) {
                i++;
            }
            if (ans.back() % 3 == 0) {
                j++;
            }
            if (ans.back() % 5 == 0) {
                k++;
            }
        }
        return ans.back();
    }
};
