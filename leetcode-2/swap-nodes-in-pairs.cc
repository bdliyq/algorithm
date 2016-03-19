// Question: https://leetcode.com/problems/swap-nodes-in-pairs/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto ans = head;
        if (head && head->next) {
            ans = head->next;
            head->next = swapPairs(ans->next);
            ans->next = head;
        }
        return ans;
    }

    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        auto curr = head;
        auto ans = head->next;
        ListNode* prev = NULL;
        while (curr && curr->next) {
            auto next = curr->next;
            curr->next = next->next;
            next->next = curr;
            if (prev) {
                prev->next = next;
            }
            prev = curr;
            curr = curr->next;
        }
        return ans;
    }
}
