#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/reverse-linked-list-ii/

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
    @param head: The head of linked list
    @param m: start position
    @param n: end position
    """
    def reverseBetween(self, head, m, n):
        # write your code here
        dummy = ListNode(0)
        writer = dummy
        cursor = head
        prev_m = dummy

        i = 1
        while cursor:
            if i <= m or i > n:
                prev_m = writer
                next = cursor.next
                cursor.next = None
                writer.next = cursor
                writer = cursor
                cursor = next
            elif i > m and i <= n:
                next = cursor.next
                cursor.next = prev_m.next
                prev_m.next = cursor
                cursor = next
            i += 1

        return dummy.next


if __name__ == '__main__':
    head = ListNode(1)
    head.next = ListNode(2)
    head.next.next = ListNode(3)
    head.next.next.next = ListNode(4)
    head.next.next.next.next = ListNode(5)

    print_linked_list(head)
    s = Solution()
    new_head = s.reverseBetween(head, 1, 5)
    print_linked_list(new_head)
