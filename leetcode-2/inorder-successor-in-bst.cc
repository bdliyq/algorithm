// Question:
// Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
//
// Note: If the given node has no in-order successor in the tree, return null.
//
// Hide Tags Tree
// Hide Similar Problems (M) Binary Tree Inorder Traversal (M) Binary Search Tree Iterator

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) {
            return NULL;
        }

        auto node = root;
        TreeNode* ans = NULL;
        while (node) {
            if (node->val <= p->val) {
                node = node->right;
            } else {
                ans = node;
                node = node->left;
            }
        }
        return ans;
    }
};
