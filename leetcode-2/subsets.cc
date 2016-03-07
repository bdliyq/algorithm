// Question: https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        helper(nums, 0, path, ans);
        return ans;
    }

    void helper(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& ans) {
        ans.push_back(path);
        for (int i = start; i < nums.size(); ++i) {
            path.push_back(nums[i]);
            helper(nums, i+1, path, ans);
            path.pop_back();
        }
    }
};
