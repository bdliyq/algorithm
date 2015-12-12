// Question: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return NULL;
        }

        int num = head->val, cnt = 1;
        ListNode* node = NULL;
        ListNode* cur = head->next;
        while (cur) {
            if (cur->val == num) {
                ++cnt;
            } else {
                if (cnt == 1) {
                    if (!node) {
                        node = head;
                    } else {
                        node = node->next;
                    }
                    node->val = num;
                }
                num = cur->val;
                cnt = 1;
            }
            cur = cur->next;
        }
        if (cnt == 1) {
            if (!node) {
                node = head;
            } else {
                node = node->next;
            }
            node->val = num;
        }
        if (node) {
            node->next = NULL;
            return head;
        } else {
            return NULL;
        }
    }
};

int main(int argc, char** argv) {
    Solution s;
    ListNode* head = new ListNode(1);
    // head->next = new ListNode(2);
    // head->next->next = new ListNode(3);
    // head->next->next->next = new ListNode(3);
    // head->next->next->next->next = new ListNode(4);
    // head->next->next->next->next->next = new ListNode(4);
    // head->next->next->next->next->next->next = new ListNode(5);
    ListNode* new_head = s.deleteDuplicates(head);
    while (new_head) {
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    cout << endl;
    return 0;
}
