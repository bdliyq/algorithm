// Question: https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<vector<int>> ans;
        helper(k, n, 1, path, ans);
        return ans;
    }

    void helper(int k, int n, int start, vector<int>& path, vector<vector<int>>& ans) {
        if (k == path.size() && n == 0) {
            ans.push_back(path);
        } else if (n > 0 && path.size() < k) {
            for (int i = start; i <= 9; ++i) {
                path.push_back(i);
                helper(k, n-i, i+1, path, ans);
                path.pop_back();
            }
        }
    }
};
