// Question: https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }

        auto slow = head;
        auto fast = head->next;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto head1 = head;
        auto head2 = slow->next;
        if (fast->next) {
            head2 = head2->next;
        }
        slow->next = NULL;

        ListNode dummy(0);
        auto curr = &dummy;
        while (head2) {
            auto next = head2->next;
            head2->next = curr->next;
            curr->next = head2;
            head2 = next;
        }

        head2 = dummy.next;
        while (head1 && head2) {
            if (head1->val != head2->val) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};
