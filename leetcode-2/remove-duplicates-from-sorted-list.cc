// Question: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        auto prev = head;
        auto curr = head->next;
        while (curr) {
            if (curr->val == prev->val) {
                curr = curr->next;
                prev->next = curr;
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
