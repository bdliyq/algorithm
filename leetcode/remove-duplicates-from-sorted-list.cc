// Question: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        ListNode* c = &dummy;
        while (head) {
            ListNode* next = head->next;
            if (c == &dummy || c->val != head->val) {
                c->next = head;
                c = c->next;
                c->next = NULL;
            }
            head = next;
        }
        return dummy.next;
    }
};
