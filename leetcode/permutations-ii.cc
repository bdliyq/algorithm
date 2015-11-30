// Question: https://leetcode.com/problems/permutations-ii/

#include "headers.h"

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> path;
        unordered_set<int> visit;
        helper(nums, visit, path, ans);
        return ans;
    }

private:
    void helper(vector<int>& nums, unordered_set<int>& visit, vector<int>& path, vector<vector<int>>& ans) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                if (visit.count(i) == 0) {
                    if (i > 0 && nums[i] == nums[i-1] && visit.count(i-1) == 0) {
                        continue;
                    }
                    path.push_back(nums[i]);
                    visit.insert(i);
                    helper(nums, visit, path, ans);
                    visit.erase(i);
                    path.pop_back();
                }
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<int> nums{1,1,2};
    vector<vector<int>> ans = s.permuteUnique(nums);
    for (auto v : ans) {
        for (auto n : v) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}
