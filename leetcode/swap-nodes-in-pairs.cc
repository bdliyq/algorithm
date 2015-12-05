// Question: https://leetcode.com/problems/swap-nodes-in-pairs/

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode* n = &dummy;
        while (n && n->next && n->next->next) {
            ListNode* t = n->next;
            n->next = t->next;
            t->next = n->next->next;
            n->next->next = t;
            n = t;
        }

        return dummy.next;

        // if (!head || !head->next) {
        //     return head;
        // }

        // ListNode dummy(0);
        // ListNode* c1 = &dummy;
        // ListNode* c2 = dummy.next;
        // int i = 0;
        // while (head) {
        //     ListNode* next = head->next;
        //     if (i%2 == 0) {
        //         c2 = c1;
        //         c1->next = head;
        //         c1 = head;
        //         c1->next = NULL;
        //     } else {
        //         head->next = c2->next;
        //         c2->next = head;
        //         c2 = head;
        //     }
        //     head = next;
        //     ++i;
        // }

        // return dummy.next;
    }
};

int main(int argc, char** argv) {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    ListNode* new_head = s.swapPairs(head);
    while (new_head) {
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    cout << endl;
    return 0;
}
