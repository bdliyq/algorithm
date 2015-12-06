// Question: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include "helper.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, (int)preorder.size()-1, 0, (int)inorder.size()-1);
    }

private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preleft, int preright, int inleft, int inright) {
        if (preleft > preright) {
            return NULL;
        }

        if (preleft == preright) {
            return new TreeNode(preorder[preleft]);
        }

        TreeNode* root = new TreeNode(preorder[preleft]);
        int place = inleft;
        while (inorder[place] != preorder[preleft]) {
            ++place;
        }
        root->left = helper(preorder, inorder, preleft+1, preleft + place-inleft, inleft, place-1);
        root->right = helper(preorder, inorder, preleft + place-inleft+1, preright, place+1, inright);
        return root;
    }
};
