// Question: Linked list insert.

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL) {}
};

ListNode* linked_list_insert(ListNode* head, int val) {
    if (!head) {
        ListNode* ans = new ListNode(val);
        ans->next = ans;
        return ans;
    }

    ListNode* cursor = head;
    do {
        if (val >= cursor->val && val <= cursor->next->val) {
            break;
        }
        if (cursor->val > cursor->next->val && (val > cursor->val || val < cursor->next->val)) {
            break;
        }
        cursor = cursor->next;
    } while (cursor != head);
    ListNode* ans = new ListNode(val);
    ans->next = cursor->next;
    cursor->next = ans;
    return ans;
}

int main(int argc, char** argv) {
    ListNode* head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head;

    ListNode* ans = linked_list_insert(head, 2);
    ListNode* cursor = ans;
    do {
        cout << cursor->val << endl;
        cursor = cursor->next;
    } while (cursor != ans);
}
