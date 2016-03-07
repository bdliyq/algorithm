// Question: https://leetcode.com/problems/combination-sum/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, path, ans, target);
        return ans;
    }

    void helper(vector<int>& candidates, int start, vector<int>& path, vector<vector<int>>& ans, int target) {
        if (target == 0) {
            if (!path.empty()) {
                ans.push_back(path);
            }
        }

        for (int i = start; i < candidates.size(); ++i) {
            int n = candidates[i];
            if (target - n >= 0) {
                path.push_back(n);
                helper(candidates, i, path, ans, target - n);
                path.pop_back();
            }
        }
    }
};
