// Question: https://leetcode.com/problems/partition-list/

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1(0);
        ListNode dummy2(0);
        ListNode* n1 = &dummy1;
        ListNode* n2 = &dummy2;
        while (head) {
            ListNode* next = head->next;
            if (head->val < x) {
                n1->next = head;
                n1 = n1->next;
                n1->next = NULL;
            } else {
                n2->next = head;
                n2 = n2->next;
                n2->next = NULL;
            }
            head = next;
        }

        n1->next = dummy2.next;
        return dummy1.next;
    }
};

int main(int argc, char** argv) {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    ListNode* new_head = s.partition(head, 3);
    while (new_head) {
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    cout << endl;
    return 0;
}
