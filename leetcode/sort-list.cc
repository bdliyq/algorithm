// Question: https://leetcode.com/problems/sort-list/

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode *h1, *h2;
        split_list(head, h1, h2);
        return merge_list(sortList(h1), sortList(h2));
    }

private:
    void split_list(ListNode* head, ListNode*& h1, ListNode*& h2) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        h1 = head;
        h2 = slow->next;
        slow->next = NULL;
    }

    ListNode* merge_list(ListNode* h1, ListNode* h2) {
        ListNode dummy(0);
        ListNode* p = &dummy;
        while (h1 && h2) {
            if (h1->val < h2->val) {
                p->next = h1;
                h1 = h1->next;
                p = p->next;
            } else {
                p->next = h2;
                h2 = h2->next;
                p = p->next;
            }
        }
        p->next = h1 ? h1 : h2;
        return dummy.next;
    }
};

int main(int argc, char** argv) {
    Solution s;
    {
        ListNode* head = new ListNode(5);
        ListNode* sorted = s.sortList(head);
        while (sorted) {
            cout << sorted->val << " ";
            sorted = sorted->next;
        }
        cout << endl;
    }
    {
        ListNode* head = new ListNode(5);
        head->next = new ListNode(4);
        ListNode* sorted = s.sortList(head);
        while (sorted) {
            cout << sorted->val << " ";
            sorted = sorted->next;
        }
        cout << endl;
    }
    {
        ListNode* head = new ListNode(5);
        head->next = new ListNode(4);
        head->next->next = new ListNode(10);
        ListNode* sorted = s.sortList(head);
        while (sorted) {
            cout << sorted->val << " ";
            sorted = sorted->next;
        }
        cout << endl;
    }
    {
        ListNode* head = new ListNode(5);
        head->next = new ListNode(4);
        head->next->next = new ListNode(10);
        head->next->next->next = new ListNode(-1);
        ListNode* sorted = s.sortList(head);
        while (sorted) {
            cout << sorted->val << " ";
            sorted = sorted->next;
        }
        cout << endl;
    }
}
