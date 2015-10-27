#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/reorder-list/

from linked_list import *

"""
Definition of ListNode
class ListNode(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""

class Solution:
    def reverseList(self, head):
        dummy = ListNode(0)
        node = head
        while node:
            next = node.next
            node.next = dummy.next
            dummy.next = node
            node = next
        return dummy.next

    """
    @param head: The first node of the linked list.
    @return: nothing
    """
    def reorderList(self, head):
        # write your code here
        if not head or not head.next:
            return

        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        reversedhead = self.reverseList(slow.next)
        slow.next = None

        cursor1 = head.next
        cursor2 = reversedhead.next
        writer = head
        writer.next = reversedhead
        writer = writer.next
        while cursor1 and cursor2:
            next1 = cursor1.next
            next2 = cursor2.next
            writer.next = cursor1
            writer = cursor1
            writer.next = cursor2
            writer = cursor2
            cursor1 = next1
            cursor2 = next2
        if cursor1:
            writer.next = cursor1
        elif cursor2:
            writer.next = cursor2

if __name__ == '__main__':
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    print_linked_list(head)
    s = Solution()
    s.reorderList(head)
    print_linked_list(head)
