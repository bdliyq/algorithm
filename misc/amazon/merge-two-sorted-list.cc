// Question: Merge two sorted list.

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL) {}
};

ListNode* merge_two_sorted_list(ListNode* a, ListNode* b) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    ListNode* cura = a;
    ListNode* curb = b;
    while (cura && curb) {
        if (cura->val <= curb->val) {
            curr->next = cura;
            curr = curr->next;
            cura = cura->next;
        } else {
            curr->next = curb;
            curr = curr->next;
            curb = curb->next;
        }
    }
    curr->next = cura ? cura : curb;
    return dummy.next;
}

int main(int argc, char** argv) {
    ListNode* a = new ListNode(1);
    a->next = new ListNode(3);
    a->next->next = new ListNode(7);
    a->next->next->next = new ListNode(9);

    ListNode* b = new ListNode(2);
    b->next = new ListNode(4);
    b->next->next = new ListNode(5);
    b->next->next->next = new ListNode(7);

    ListNode* l = merge_two_sorted_list(a, b);
    while (l) {
        cout << l->val << endl;
        l = l->next;
    }

    return 0;
}
