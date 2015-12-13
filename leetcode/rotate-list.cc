// Question: https://leetcode.com/problems/rotate-list/

#include "headers.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) {
            return head;
        }

        int cnt = 1;
        ListNode* cur = head;
        while (cur->next) {
            ++cnt;
            cur = cur->next;
        }
        ListNode* tail = cur;

        if (k % cnt == 0) {
            return head;
        }

        int n = cnt - k % cnt;
        cur = head;
        while (--n) {
            cur = cur->next;
        }

        ListNode* ans = cur->next;
        cur->next = NULL;
        tail->next = head;
        return ans;
    }
};

int main(int argc, char** argv) {
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    ListNode* ans = s.rotateRight(head, 2);
    while (ans) {
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
}
