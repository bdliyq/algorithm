// Question: https://leetcode.com/problems/partition-list/

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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0), dummy2(0);
        auto node = head;
        auto cursor1 = &dummy1;
        auto cursor2 = &dummy2;
        while (node) {
            auto next = node->next;
            if (node->val < x) {
                node->next = cursor1->next;
                cursor1->next = node;
                cursor1 = node;
            } else {
                node->next = cursor2->next;
                cursor2->next = node;
                cursor2 = node;
            }
            node = next;
        }
        cursor1->next = dummy2.next;
        return dummy1.next;
    }
};
