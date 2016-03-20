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

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) {
            return root;
        }

        if (p->right) {
            auto n = p->right;
            while (n->left) {
                n = n->left;
            }
            return n;
        }

        auto successor = NULL;
        auto ancessor = root;
        while (ancessor != p) {
            if (ancessor->val <= p->val) {
                ancessor = ancessor->right;
            } else {
                successor = ancessor;
                ancessor = ancessor->left;
            }
        }
        return successor;
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) {
            return root;
        }

        if (p->right) {
            auto n = p->right;
            while (n->left) {
                n = n->left;
            }
            return n;
        }

        auto parent = p->parent;
        while (parent && parent->val < p->val) {
            parent = parent->parent;
        }
        return parent;
    }
};
