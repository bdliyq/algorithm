// Question: https://leetcode.com/problems/permutations-ii/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_set<int> visited;
        vector<int> path;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        helper(nums, visited, path, ans);
        return ans;
    }

    void helper(vector<int>& nums, unordered_set<int> visited, vector<int>& path, vector<vector<int>>& ans) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
        } else if (path.size() < nums.size()) {
            for (int i = 0; i < nums.size(); ++i) {
                if (visited.count(i) == 0) {
                    if (i > 0 && nums[i] == nums[i-1] && visited.count(i-1) == 0) {
                        continue;
                    }
                    visited.insert(i);
                    path.push_back(nums[i]);
                    helper(nums, visited, path, ans);
                    path.pop_back();
                    visited.erase(i);
                }
            }
        }
    }
};
