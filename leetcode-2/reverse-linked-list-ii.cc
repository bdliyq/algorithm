// Question: https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m == n || !head) {
            return head;
        }
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prev = &dummy, *curr = prev->next, *n1 = NULL, *n2 = NULL;
        int idx = 0;
        while (curr) {
            ++idx;
            if (idx == m) {
                n1 = prev;
            } else if (idx == n) {
                n2 = curr->next;
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        reverse(n1, n2);
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
