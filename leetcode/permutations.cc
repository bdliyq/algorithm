// Question: https://leetcode.com/problems/permutations/

#include "headers.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        unordered_set<int> visit;
        helper(nums, visit, path, ans);
        return ans;
    }

private:
    void helper(vector<int>& nums, unordered_set<int>& visit, vector<int>& path, vector<vector<int>>& ans) {
        if (path.size() >= nums.size()) {
            ans.push_back(path);
        } else {
            for (auto n : nums) {
                if (visit.count(n) == 0) {
                    path.push_back(n);
                    visit.insert(n);
                    helper(nums, visit, path, ans);
                    visit.erase(n);
                    path.pop_back();
                }
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1,2,3};
    vector<vector<int>> ans = s.permute(nums);
    for (auto v : ans) {
        for (auto n : v) {
            cout << n << " ";
        }
        cout << endl;
    }
}
