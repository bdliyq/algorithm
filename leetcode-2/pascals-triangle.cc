// Question: https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows <= 0) {
            return ans;
        }
        ans.push_back(vector<int>{1});
        for (int i = 1; i < numRows; ++i) {
            vector<int> line(i+1, 0);
            line[0] = ans.back()[0];
            line[i] = ans.back().back();
            for (int j = 1; j < i; ++j) {
                line[j] = ans.back()[j-1] + ans.back()[j];
            }
            ans.push_back(line);
        }
        return ans;
    }
};
