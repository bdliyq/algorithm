// Question: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, (int)inorder.size()-1, 0, (int)postorder.size()-1);
    }

    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int il, int ir, int pl, int pr) {
        if (pl > pr) {
            return NULL;
        }
        if (pl == pr) {
            return new TreeNode(postorder[pr]);
        }
        int i = il;
        while (i <= ir) {
            if (inorder[i] == postorder[pr]) {
                break;
            }
            ++i;
        }
        int len = i - il;
        auto root = new TreeNode(postorder[pr]);
        root->left = helper(inorder, postorder, il, i-1, pl, pl+len-1);
        root->right = helper(inorder, postorder, i+1, ir, pl+len, pr-1);
        return root;
    }
};
