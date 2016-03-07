// Question: https://leetcode.com/problems/subsets-ii/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> ans;
        helper(nums, 0, path, ans);
        return ans;
    }

    void helper(vector<int>& nums, int k, vector<int>& path, vector<vector<int>>& ans) {
        ans.push_back(path);
        for (int i = k; i < nums.size(); ++i) {
            if (i > k && nums[i-1] == nums[i]) {
                continue;
            }
            path.push_back(nums[i]);
            helper(nums, i+1, path, ans);
            path.pop_back();
        }
    }
};
