// Question: https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return NULL;
        }

        auto node = headA;
        ListNode* tail = NULL;
        while (node) {
            tail = node;
            node = node->next;
        }

        tail->next = headB;

        auto slow = headA;
        auto fast = headA;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                auto entry = headA;
                while (slow != entry) {
                    slow = slow->next;
                    entry = entry->next;
                }
                tail->next = NULL;
                return entry;
            }
        }

        tail->next = NULL;

        return NULL;
    }
};
