// Question: Reverse second half of linked list.

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(NULL) {}
};

ListNode* reverse_second_half_of_linked_list(ListNode* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return head;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* reader = slow->next;
    slow->next = NULL;
    ListNode* cursor = slow->next;

    while (reader) {
        ListNode* next_reader = reader->next;
        reader->next = cursor;
        cursor = reader;
        slow->next = reader;
        reader = next_reader;
    }

    return head;
}

int main(int argc, char** argv) {
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        ListNode* new_head = reverse_second_half_of_linked_list(head);
        while (new_head) {
            cout << new_head->val << endl;
            new_head = new_head->next;
        }
        cout << "******" << endl;
    }
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        ListNode* new_head = reverse_second_half_of_linked_list(head);
        while (new_head) {
            cout << new_head->val << endl;
            new_head = new_head->next;
        }
        cout << "******" << endl;
    }
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        ListNode* new_head = reverse_second_half_of_linked_list(head);
        while (new_head) {
            cout << new_head->val << endl;
            new_head = new_head->next;
        }
        cout << "******" << endl;
    }
    {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);
        ListNode* new_head = reverse_second_half_of_linked_list(head);
        while (new_head) {
            cout << new_head->val << endl;
            new_head = new_head->next;
        }
        cout << "******" << endl;
    }

    return 0;
}
