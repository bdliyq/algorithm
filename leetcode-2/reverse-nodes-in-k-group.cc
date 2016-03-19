// Question: https://leetcode.com/problems/reverse-nodes-in-k-group/

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        auto prev = &dummy;
        auto curr = prev->next;
        int count = 0;
        while (curr) {
            ++count;
            if (count == k) {
                prev = reverse(prev, curr->next);
                curr = prev->next;
                count = 0;
            } else {
                curr = curr->next;
            }
        }
        return dummy.next;
    }

    ListNode* reverse(ListNode* prev, ListNode* next) {
        auto last = prev->next;
        auto curr = last->next;
        while (curr != next) {
            last->next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = last->next;
        }
        return last;
    }
};
