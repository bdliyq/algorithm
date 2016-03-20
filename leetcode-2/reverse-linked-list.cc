// Question: https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(0);
        auto cursor = &dummy;
        auto node = head;
        while (node) {
            auto next = node->next;
            node->next = cursor->next;
            cursor->next = node;
            node = next;
        }
        return dummy.next;
    }

    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        auto ans = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return ans;
    }
};
