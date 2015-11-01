#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/reverse-nodes-in-k-group/

from linked_list import *

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @param k, an integer
    # @return a ListNode
    def reverseKGroup(self, head, k):
        # Write your code here
        if k == 1 or not head:
            return head

        dummy = ListNode(0)
        r = head
        t = dummy
        while r:
            w = t
            t = None
            i = 0

            m = r
            should_reverse = False
            while m and i < k:
                m = m.next
                i += 1
            if i == k:
                should_reverse = True

            if should_reverse:
                i = 0
                while r and i < k:
                    n = r.next
                    r.next = w.next
                    w.next = r
                    if not t:
                        t = r
                    r = n
                    i += 1
            else:
                w.next = r
                break
        return dummy.next

if __name__ == '__main__':
    s = Solution()
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)
    new_head = s.reverseKGroup(head, 3)
    print_linked_list(new_head)
