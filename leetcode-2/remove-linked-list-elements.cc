// Question: https://leetcode.com/problems/remove-linked-list-elements/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        auto prev = &dummy;
        auto curr = dummy.next;
        while (curr) {
            if (curr->val != val) {
                prev = curr;
                curr = curr->next;
            } else {
                curr = curr->next;
                prev->next = curr;
            }
        }
        return dummy.next;
    }
};
