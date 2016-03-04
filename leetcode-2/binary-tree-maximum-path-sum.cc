// Question: https://leetcode.com/problems/binary-tree-maximum-path-sum/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }

    int helper(TreeNode* root, int& ans) {
        if (!root) {
            return 0;
        }

        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        int arch = left + right + root->val;
        int single = max(root->val, max(left, right) + root->val);
        ans = max(max(single, arch), ans);
        return single;
    }
};
