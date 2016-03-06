// Question: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, (int)preorder.size()-1, 0, (int)inorder.size()-1);
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
        if (pl > pr) {
            return NULL;
        }
        if (pl == pr) {
            return new TreeNode(preorder[pl]);
        }
        int i = il;
        while (i <= ir) {
            if (preorder[pl] == inorder[i]) {
                break;
            }
            ++i;
        }
        int len = i-il;

        auto root = new TreeNode(preorder[pl]);
        root->left = helper(preorder, inorder, pl+1, pl+len, il, i-1);
        root->right = helper(preorder, inorder, pl+len+1, pr, i+1, ir);
        return root;
    }
};
