// Question: https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        auto node = head;
        int count = 0;
        ListNode* tail = NULL;
        while (node) {
            ++count;
            tail = node;
            node = node->next;
        }

        if (k % count == 0) {
            return head;
        }

        int n = count - k % count;
        node = head;
        while (--n) {
            node = node->next;
        }

        auto ans = node->next;
        node->next = NULL;
        tail->next = head;
        return ans;
    }
};
