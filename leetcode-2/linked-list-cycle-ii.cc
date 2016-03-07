// Question: https://leetcode.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        if (!head) {
            return NULL;
        }

        auto slow = head;
        auto fast = head;
        ListNode* ans = NULL;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                ans = head;
                while (slow != ans) {
                    slow = slow->next;
                    ans = ans->next;
                }
                return ans;
            }
        }
        return ans;
    }
};
