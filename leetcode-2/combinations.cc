// Question: https://leetcode.com/problems/combinations/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        helper(1, n, k, path, ans);
        return ans;
    }

    void helper(int start, int end, int k, vector<int>& path, vector<vector<int>>& ans) {
        if (path.size() == k) {
            ans.push_back(path);
        } else if (path.size() < k) {
            for (int i = start; i <= end; ++i) {
                path.push_back(i);
                helper(i+1, end, k, path, ans);
                path.pop_back();
            }
        }
    }
};
