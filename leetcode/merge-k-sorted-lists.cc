// Question: https://leetcode.com/problems/merge-k-sorted-lists/

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
    bool operator() (ListNode* n1, ListNode* n2) {
        return n1->val < n2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* c = &dummy;

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto n : lists) {
            if (n) {
                pq.push(n);
            }
        }

        while (!pq.empty()) {
            ListNode* n = pq.top();
            pq.pop();
            if (n->next) {
                pq.push(n->next);
            }

            n->next = c->next;
            c->next = n;
            c = n;
            c->next = NULL;
        }

        return dummy.next;
    }
};

int main(int argc, char** argv) {
    Solution s;
}
