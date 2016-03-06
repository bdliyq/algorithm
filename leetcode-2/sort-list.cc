// Question: https://leetcode.com/problems/sort-list/

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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* h1, *h2;
        split_list(head, h1, h2);
        return merge_list(sortList(h1), sortList(h2));
    }

    void split_list(ListNode* head, ListNode*& h1, ListNode*& h2) {
        h1 = NULL;
        h2 = NULL;
        if (!head) {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        h1 = head;
        h2 = slow->next;
        slow->next = NULL;
    }

    ListNode* merge_list(ListNode* h1, ListNode* h2) {
        ListNode dummy;
        ListNode* cursor = &dummy;
        while (h1 && h2) {
            if (h1->val < h2->val) {
                cursor->next = h1;
                h1 = h1->next;
                cursor = cursor->next;
                cursor->next = NULL;
            } else {
                cursor->next = h2;
                h2 = h2->next;
                cursor = cursor->next;
                cursor->next = NULL;
            }
        }
        cursor->next = (h1 ? h1 : h2);
        return dummy.next;
    }
};
