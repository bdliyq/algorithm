// Question: https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        auto curr = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                auto next = l1->next;
                l1->next = curr->next;
                curr->next = l1;
                curr = curr->next;
                l1 = next;
            } else {
                auto next = l2->next;
                l2->next = curr->next;
                curr->next = l2;
                curr = curr->next;
                l2 = next;
            }
        }
        curr->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
