// Question: https://leetcode.com/problems/gray-code/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        if (n == 0) {
            return ans;
        }

        ans.push_back(1);
        for (int i = 1; i < n; ++i) {
            int count = ans.size();
            for (int j = count-1; j >= 0; --j) {
                ans.push_back(ans.at(j) | (1 << i));
            }
        }

        return ans;
    }
};
