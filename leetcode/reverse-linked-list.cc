// Question: https://leetcode.com/problems/reverse-linked-list/

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode dummy(0);
        while (head) {
            ListNode* t = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = t;
        }

        return dummy.next;
    }
};

int main(int argc, char** argv) {
    Solution s;
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        ListNode* ans = s.reverseList(head);
        while (ans) {
            cout << ans->val << " ";
            ans = ans->next;
        }
        cout << endl;
    }
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        ListNode* ans = s.reverseList(head);
        while (ans) {
            cout << ans->val << " ";
            ans = ans->next;
        }
        cout << endl;
    }
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        ListNode* ans = s.reverseList(head);
        while (ans) {
            cout << ans->val << " ";
            ans = ans->next;
        }
        cout << endl;
    }
}
