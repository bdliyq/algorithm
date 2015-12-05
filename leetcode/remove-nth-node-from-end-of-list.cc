// Question: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) {
            return NULL;
        }

        ListNode* fast = head;
        int i = 0;
        while (i++ < n) {
            fast = fast->next;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* node = &dummy;
        while (fast) {
            node = node->next;
            fast = fast->next;
        }

        node->next = node->next->next;
        return dummy.next;
    }
};

int main(int argc, char** argv) {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* new_head = s.removeNthFromEnd(head, 5);
    while (new_head) {
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    cout << endl;
}
