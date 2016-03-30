// Question: 检查一棵二叉树是否是bst。

struct TreeNode* {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool solve(TreeNode* root) {
    return helper(root, LONG_MAX, LONG_MIN);
}

bool helper(TreeNode* root, long maxv, long minv) {
    if (!root) {
        return true;
    }
    if (root->val > maxv || root->val < minv) {
        return false;
    }
    return helper(root->left, root->val, minv) && helper(root->right, maxv, root->val);
}
