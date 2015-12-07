// Question: https://leetcode.com/problems/copy-list-with-random-pointer/

#include "headers.h"

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* node = head;
        while (node) {
            RandomListNode* copy = new RandomListNode(node->label);
            copy->next = node->next;
            node->next = copy;
            node = copy->next;
        }

        node = head;
        while (node) {
            if (node->random) {
                node->next->random = node->random->next;
            }
            node = node->next->next;
        }

        RandomListNode dummy(0);
        RandomListNode* cursor = &dummy;
        node = head;
        while (node) {
            cursor->next = node->next;
            cursor = cursor->next;
            node->next = node->next->next;
            node = node->next;
            cursor->next = NULL;
        }

        return dummy.next;
    }
};
