// Question: Minimum path sum.

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

int minimum_path_sum(TreeNode* node) {
    if (!node) {
        return 0;
    }
    if (!node->left && node->right) {
        return minimum_path_sum(node->right) + node->val;
    }
    if (node->left && !node->right) {
        return minimum_path_sum(node->left) + node->val;
    }
    return min(minimum_path_sum(node->left), minimum_path_sum(node->right)) + node->val;
}

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(7);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(6);
    std::cout << minimum_path_sum(root) << std::endl;
}
