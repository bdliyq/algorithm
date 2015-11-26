// Question: https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cursor = &dummy;
        int carry = 0;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            int res = sum % 10;
            carry = sum / 10;
            ListNode* node = new ListNode(res);
            cursor->next = node;
            cursor = node;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* left = l1 ? l1 : l2;
        while (left) {
            int sum = left->val + carry;
            int res = sum % 10;
            carry = sum / 10;
            ListNode* node = new ListNode(res);
            cursor->next = node;
            cursor = node;
            left = left->next;
        }
        if (carry > 0) {
            ListNode* node = new ListNode(carry);
            cursor->next = node;
        }
        return dummy.next;
    }
};
