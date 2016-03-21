// Question: https://leetcode.com/problems/merge-k-sorted-lists/

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
    bool operator () (ListNode* n1, ListNode* n2) {
        return n1->val > n2->val;  // 大的放后面，小的先出队。
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }
        if (lists.size() == 1) {
            return lists[0];
        }
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto node : lists) {
            if (node) {
                pq.push(node);
            }
        }

        ListNode dummy(0);
        auto cursor = &dummy;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            if (node->next) {
                pq.push(node->next);
            }

            node->next = cursor->next;
            cursor->next = node;
            cursor = node;
        }
        return dummy.next;
    }
};

int main(int argc, char** argv) {
}
