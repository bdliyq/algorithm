// Question: https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 0) {
            return vector<int>();
        }

        vector<int> ans(rowIndex+1, 0);
        ans[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            ans[i] = 1;
            for (int j = i-1; j >= 1; --j) {
                ans[j] = ans[j-1] + ans[j];
            }
        }

        return ans;
    }
};
