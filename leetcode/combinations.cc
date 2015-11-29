// Question: https://leetcode.com/problems/combinations/

#include "headers.h"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        helper(n, k, 1, path, ans);
        return ans;
    }

private:
    void helper(int n, int k, int start, vector<int>& path, vector<vector<int>>& ans) {
        if (path.size() == k) {
            ans.push_back(path);
            return;
        }

        for (int i = start; i <= n; ++i) {
            path.push_back(i);
            helper(n, k, i+1, path, ans);
            path.pop_back();
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    vector<vector<int>> ans = s.combine(4,3);
    for (auto v : ans) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
