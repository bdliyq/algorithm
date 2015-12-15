// Question: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

#include "headers.h"

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) {
            return;
        }

        vector<TreeLinkNode*> q;
        q.push_back(root);
        int offset = 0;
        while (offset != q.size()) {
            int cnt = q.size();
            while (offset < cnt) {
                if (offset < cnt-1) {
                    q[offset]->next = q[offset+1];
                }
                if (q[offset]->left) {
                    q.push_back(q[offset]->left);
                }
                if (q[offset]->right) {
                    q.push_back(q[offset]->right);
                }
                ++offset;
            }
        }
    }
};
