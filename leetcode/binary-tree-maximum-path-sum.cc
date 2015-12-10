// Question: https://leetcode.com/problems/binary-tree-maximum-path-sum/

#include "headers.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }

private:
    int helper(TreeNode* root, int& ans) {
        if (!root) {
            return 0;
        }
        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        int arch = left + right + root->val;
        int single = max(root->val, max(left, right) + root->val);
        ans = max(ans, max(arch, single));
        return single;
    }
};

int main(int argc, char** argv) {
    Solution s;
    TreeNode* root = new TreeNode(-3);
    root->left = new TreeNode(1);
    cout << s.maxPathSum(root) << endl;
    return 0;
}
