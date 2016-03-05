// Question: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        int curr = 1;
        int next = 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);

            if (node->left) {
                q.push(node->left);
                ++next;
            }
            if (node->right) {
                q.push(node->right);
                ++next;
            }

            if (--curr == 0) {
                swap(curr, next);
                ans.push_back(level);
                level.clear();
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};
