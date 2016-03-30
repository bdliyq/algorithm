// Question: 给出binary tree的height。

int solve(TreeNode* root) {
    if (!root) {
        return 0;
    }
    return max(solve(root->left), solve(root->right)) + 1;
}
