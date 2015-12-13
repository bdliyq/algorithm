// Question: https://leetcode.com/problems/reorder-list/

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }

        ListNode* slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* cur = slow->next;
        slow->next = NULL;
        ListNode dummy(0);
        ListNode* t = dummy.next;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = t;
            t = cur;
            cur = next;
        }

        ListNode* cur1 = head->next;
        ListNode* cur2 = t;
        cur = head;
        while (cur1 && cur2) {
            ListNode* n1 = cur1->next, *n2 = cur2->next;

            cur2->next = cur->next;
            cur->next = cur2;
            cur = cur2;
            cur->next = NULL;
            cur2 = n2;

            cur1->next = cur->next;
            cur->next = cur1;
            cur = cur1;
            cur->next = NULL;
            cur1 = n1;

        }
        if (cur2) {
            cur2->next = cur->next;
            cur->next = cur2;
        }
        if (cur1) {
            cur1->next = cur->next;
            cur->next = cur1;
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(4);
    // head->next->next->next->next = new ListNode(5);
    // head->next->next->next->next->next = new ListNode(6);
    s.reorderList(head);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}
