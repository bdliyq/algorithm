// Question: Subtree.

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

bool is_sametree(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) {
        return true;
    }
    if ((t1 && !t2) || (t2 && !t1) || (t1->val != t2->val)) {
        return false;
    }
    return is_sametree(t1->left, t2->left) && is_sametree(t1->right, t2->right);
}

bool is_subtree(TreeNode* t1, TreeNode* t2) {
    if (!t2) {
        return true;
    }
    if (!t1) {
        return false;
    }

    queue<TreeNode*> q;
    q.push(t1);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (is_sametree(node, t2)) {
            return true;
        }

        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
    return false;
}

int main(int argc, char** argv) {
    is_subtree(NULL, NULL);
}
