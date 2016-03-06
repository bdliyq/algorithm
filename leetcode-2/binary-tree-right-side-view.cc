// Question: https://leetcode.com/problems/binary-tree-right-side-view/
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        int curr = 1;
        int next = 0;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
                ++next;
            }
            if (node->right) {
                q.push(node->right);
                ++next;
            }
            --curr;
            if (curr == 0) {
                ans.push_back(node->val);
                swap(curr, next);
            }
        }
        return ans;
    }
};
