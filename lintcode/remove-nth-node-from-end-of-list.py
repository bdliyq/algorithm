#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/remove-nth-node-from-end-of-list/

from linked_list import *

"""
Definition of ListNode
class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""
class Solution:
    """
    @param head: The first node of linked list.
    @param n: An integer.
    @return: The head of linked list.
    """
    def removeNthFromEnd(self, head, n):
        # write your code here
        if n == 0:
            return head

        fast = head
        for i in xrange(n):
            fast = fast.next

        slow = head
        prev_slow = None
        while fast:
            prev_slow = slow
            slow = slow.next
            fast = fast.next

        if not prev_slow:
            return head.next
        else:
            prev_slow.next = slow.next
            return head

if __name__ == '__main__':
    head = create_linked_list([1,2,3,4,5,6])
    s = Solution()
    head = s.removeNthFromEnd(head, 0)
    print_linked_list(head)
    head = s.removeNthFromEnd(head, 1)
    print_linked_list(head)
    head = s.removeNthFromEnd(head, 5)
    print_linked_list(head)

