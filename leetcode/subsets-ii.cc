// Question: https://leetcode.com/problems/subsets-ii/

#include "headers.h"

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        helper(nums, path, ans);
        return ans;
    }

private:
    void helper(vector<int> nums, vector<int>& path, vector<vector<int>>& ans) {
        ans.push_back(path);
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i-1] == nums[i]) {
                continue;
            }
            path.push_back(nums[i]);
            helper(vector<int>(nums.begin()+i+1, nums.end()), path, ans);
            path.pop_back();
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1,2,2};
    vector<vector<int>> ans = s.subsetsWithDup(nums);
    for (auto v : ans) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
