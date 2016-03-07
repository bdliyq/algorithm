// Question: https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> visited;
        vector<int> path;
        vector<vector<int>> ans;
        helper(path, ans, visited, nums);
        return ans;
    }

    void helper(vector<int>& path, vector<vector<int>>& ans, unordered_set<int>& visited, vector<int>& nums) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
        } else if (path.size() < nums.size()) {
            for (int i = 0; i < nums.size(); ++i) {
                int n = nums[i];
                if (visited.count(n) == 0) {
                    path.push_back(n);
                    visited.insert(n);
                    helper(path, ans, visited, nums);
                    visited.erase(n);
                    path.pop_back();
                }
            }
        }
    }
};
