// Question: https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> ans;
        helper(candidates, 0, target, path, ans);
        return ans;
    }

    void helper(vector<int>& candidates, int start, int target, vector<int>& path, vector<vector<int>>& ans) {
        if (target == 0) {
            if (!path.empty()) {
                ans.push_back(path);
            }
        } else if (target > 0) {
            for (int i = start; i < candidates.size(); ++i) {
                if (i > start && candidates[i] == candidates[i-1]) {
                    continue;
                }
                path.push_back(candidates[i]);
                helper(candidates, i+1, target - candidates[i], path, ans);
                path.pop_back();
            }
        }
    }
};
