// Question: https://leetcode.com/problems/copy-list-with-random-pointer/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        auto cursor = head;
        while (cursor) {
            auto copy = new RandomListNode(cursor->label);
            copy->next = cursor->next;
            cursor->next = copy;
            cursor = copy->next;
        }

        cursor = head;
        while (cursor) {
            if (cursor->random) {
                cursor->next->random = cursor->random->next;
            }
            cursor = cursor->next->next;
        }

        cursor = head;
        RandomListNode dummy(0);
        auto new_cursor = &dummy;
        while (cursor) {
            new_cursor->next = cursor->next;
            cursor->next = cursor->next->next;
            cursor = cursor->next;
            new_cursor = new_cursor->next;
            new_cursor->next = NULL;
        }

        return dummy.next;
    }
};
