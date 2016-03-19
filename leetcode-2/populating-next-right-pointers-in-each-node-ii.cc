// Question: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }

        TreeLinkNode* curr_head = root, *next_head = NULL;
        while (curr_head) {
            auto node = curr_head;
            TreeLinkNode* tail = NULL;
            while (node) {
                TreeLinkNode* sub = NULL;
                if (node->left && node->right) {
                    node->left->next = node->right;
                }

                if (node->left) {
                    sub = node->left;
                } else if (node->right) {
                    sub = node->right;
                }

                if (sub) {
                    if (!next_head) {
                        next_head = sub;
                        tail = sub;
                    } else {
                        tail->next = sub;
                    }
                    while (tail->next) {
                        tail = tail->next;
                    }
                }

                node = node->next;
            }

            curr_head = next_head;
            next_head = NULL;
        }
    }
};
