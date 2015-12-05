// Question: https://leetcode.com/problems/combination-sum-iii/

#include "headers.h"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<vector<int>> ans;
        helper(k, n, path, ans);
        return ans;
    }

private:
    void helper(int k, int n, vector<int>&path, vector<vector<int>>& ans) {
        if (path.size() == k && n == 0) {
            ans.push_back(path);
        } else {
            int i = 0;
            if (!path.empty()) {
                i = path.back();
            }
            for (int j = i+1; j <= 9; ++j) {
                if (j <= n) {
                    path.push_back(j);
                    helper(k, n-j, path, ans);
                    path.pop_back();
                }
            }
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> ans = s.combinationSum3(3, 9);
    for (auto v : ans) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
