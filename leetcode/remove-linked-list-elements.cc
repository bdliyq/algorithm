// Question: https://leetcode.com/problems/remove-linked-list-elements/

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        ListNode* c = &dummy;
        while (head) {
            ListNode* next = head->next;
            if (head->val != val) {
                c->next = head;
                c = c->next;
                c->next = NULL;
            }
            head = next;
        }
        return dummy.next;
    }
};
