// Question: https://leetcode.com/problems/palindrome-linked-list/

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = slow->next;
        if (fast->next) {
            head2 = head2->next;
        }
        slow->next = NULL;

        ListNode dummy(0);
        while (head2) {
            ListNode* t = dummy.next;
            dummy.next = head2;
            ListNode* head2_next = head2->next;
            head2->next = t;
            head2 = head2_next;
        }

        ListNode* cur1 = head;
        ListNode* cur2 = dummy.next;
        while (cur1 && cur2 && cur1->val == cur2->val) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1 == NULL && cur2 == NULL;
    }
};

int main(int argc, char** argv) {
    Solution s;
    {
        ListNode* head = new ListNode(1);
        cout << s.isPalindrome(head) << endl;
        // true
    }
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(1);
        cout << s.isPalindrome(head) << endl;
        // true
    }
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        cout << s.isPalindrome(head) << endl;
        // false
    }
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(1);
        cout << s.isPalindrome(head) << endl;
        // true
    }
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        cout << s.isPalindrome(head) << endl;
        // false
    }
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(2);
        head->next->next->next = new ListNode(1);
        cout << s.isPalindrome(head) << endl;
        // true
    }
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(1);
        cout << s.isPalindrome(head) << endl;
        // false
    }
    return 0;
}
