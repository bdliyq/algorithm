// Question: https://leetcode.com/problems/insertion-sort-list/

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(0);
        while (head) {
            ListNode* next = head->next;

            ListNode* c = &dummy;
            while (c->next && c->next->val < head->val) {
                c = c->next;
            }
            head->next = c->next;
            c->next = head;

            head = next;
        }
        return dummy.next;
    }
};

int main(int argc, char** argv) {
    Solution s;
    ListNode* head = new ListNode(3);
    head->next = new ListNode(5);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(2);
    ListNode* new_head = s.insertionSortList(head);
    while (new_head) {
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    cout << endl;
    return 0;
}
