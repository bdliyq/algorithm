// Question: Binary tree.

#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

int max_depth(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return max(max_depth(root->left), max_depth(root->right)) + 1;
}

int min_depth(TreeNode* root) {
    if (root == NULL) {
        return INT_MAX;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return min(min_depth(root->left), min_depth(root->right)) + 1;
}

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(5);
    cout << max_depth(root) << endl;
    cout << min_depth(root) << endl;
}
