// Question: Linked list loop.

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL) {}
};

ListNode* linked_list_loop_detection(ListNode* head) {
    if (!head || !head->next) {
        return NULL;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* entry = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            while (entry != slow) {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }

    return NULL;
}

int main(int argc, char** argv) {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next->next;
    ListNode* node = linked_list_loop_detection(head);
    if (node) {
        cout << node->val << endl;
    } else {
        cout << "NULL" << endl;
    }
    return 0;
}
