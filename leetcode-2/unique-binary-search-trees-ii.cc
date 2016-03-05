// Question: https://leetcode.com/problems/unique-binary-search-trees-ii/

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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode*>();
        }
        return helper(1, n);
    }

    vector<TreeNode*> helper(int start, int end) {
        vector<TreeNode*> ans;
        if (start > end) {
            ans.push_back(NULL);
            return ans;
        }

        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = helper(start, i-1);
            vector<TreeNode*> right = helper(i+1, end);
            for (auto node_left : left) {
                for (auto node_right : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = node_left;
                    root->right = node_right;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }
};
