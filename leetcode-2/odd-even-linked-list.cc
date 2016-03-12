// Question: https://leetcode.com/problems/odd-even-linked-list/

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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode dummy1(0), dummy2(0);
        auto curr1 = &dummy1, curr2 = &dummy2;
        int cnt = 1;
        auto node = head;
        while (node) {
            auto next = node->next;
            if (cnt % 2 == 1) {
                node->next = curr1->next;
                curr1->next = node;
                curr1 = curr1->next;
            } else {
                node->next = curr2->next;
                curr2->next = node;
                curr2 = curr2->next;
            }
            node = next;
            ++cnt;
        }
        curr1->next = dummy2.next;
        return dummy1.next;
    }
};
