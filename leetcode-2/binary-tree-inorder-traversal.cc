// Question: https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }

        TreeNode* node = root;
        stack<TreeNode*> s;
        while (node || !s.empty()) {
            if (node) {
                s.push(node);
                node = node->left;
            } else {
                node = s.top();
                s.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }

        return ans;
    }
};
