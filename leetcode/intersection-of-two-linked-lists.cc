// Question: https://leetcode.com/problems/intersection-of-two-linked-lists/

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return NULL;
        }

        ListNode* c = headA;
        while (c->next) {
            c = c->next;
        }
        c->next = headB;

        ListNode* fast = headA;
        ListNode* slow = headA;
        ListNode* entry = NULL;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                entry = headA;
                while (slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                c->next = NULL;
                return entry;
            }
        }
        c->next = NULL;
        return NULL;
    }
};
