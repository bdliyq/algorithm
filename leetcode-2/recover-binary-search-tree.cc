// Question:https://leetcode.com/problems/recover-binary-search-tree/

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
    void recoverTree(TreeNode* root) {
        if (!root) {
            return;
        }

        vector<TreeNode*> nodes;
        vector<int> vals;
        TreeNode* node = root;
        stack<TreeNode*> s;
        while (!s.empty() || node) {
            if (node) {
                s.push(node);
                node = node->left;
            } else {
                node = s.top();
                s.pop();
                nodes.push_back(node);
                vals.push_back(node->val);
                node = node->right;
            }
        }

        sort(vals.begin(), vals.end());
        for (int i = 0; i < nodes.size(); ++i) {
            nodes[i]->val = vals[i];
        }
    }
};
