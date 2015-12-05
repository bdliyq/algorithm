// Question: https://leetcode.com/problems/reverse-linked-list-ii/

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode dummy(0);
        ListNode* c1 = dummy.next;
        ListNode* c2 = &dummy;
        int i = 0;
        while (head) {
            ++i;
            ListNode* next = head->next;
            if (i <= m || i > n) {
                c2->next = head;
                c1 = c2;
                c2 = c2->next;
                c2->next = NULL;
            } else if (i > m && i <= n) {
                head->next = c1->next;
                c1->next = head;
            }
            head = next;
        }
        return dummy.next;
    }
};

int main(int argc, char** argv) {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* new_head = s.reverseBetween(head, 2, 4);
    while (new_head) {
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    cout << endl;
    return 0;
}
