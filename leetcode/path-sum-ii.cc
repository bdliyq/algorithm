// Question: https://leetcode.com/problems/path-sum-ii/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        return helper(root, sum, vector<int>());
    }

private:
    vector<vector<int>> helper(TreeNode* root, int sum, vector<int> path) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }

        int left = sum - root->val;
        if (left == 0 && !root->left && !root->right) {
            path.push_back(root->val);
            ans.push_back(path);
        } else {
            path.push_back(root->val);
            auto l = helper(root->left, left, path);
            auto r = helper(root->right, left, path);
            for (auto i : l) {
                ans.push_back(i);
            }
            for (auto i : r) {
                ans.push_back(i);
            }
        }

        return ans;
    }

};

int main(int argc, char** argv) {
    Solution s;
    TreeNode* root = new TreeNode(-2);
    root->left = new TreeNode(-3);
    vector<vector<int>> ans = s.pathSum(root, -5);
    for (auto v : ans) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
