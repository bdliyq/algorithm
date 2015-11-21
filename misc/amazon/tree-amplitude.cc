// Question: Tree amplitude.

#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

int helper(TreeNode* root, int min, int max) {
    if (!root) {
        return max - min;
    }
    min = std::min(min, root->val);
    max = std::max(max, root->val);
    return std::max(helper(root->left, min, max), helper(root->right, min, max));
}

int tree_amplitude(TreeNode* root) {
    if (!root) {
        return 0;
    }

    return helper(root, root->val, root->val);
}

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(12);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->right = new TreeNode(6);
    root->left->left = new TreeNode(4);
    cout << tree_amplitude(root) << endl;
}
