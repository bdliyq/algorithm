#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/partition-list/

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
    @param x: an integer
    @return: a ListNode
    """
    def partition(self, head, x):
        # write your code here
        if not head or not head.next:
            return head

        small = None
        small_cursor = None
        large = None
        large_cursor = None

        while head:
            if head.val < x:
                temp = head.next
                if not small:
                    small = head
                    small_cursor = small
                    small_cursor.next = None
                else:
                    small_cursor.next = head
                    small_cursor = small_cursor.next
                    small_cursor.next = None
                head = temp
            else:
                temp = head.next
                if not large:
                    large = head
                    large_cursor = large
                    large_cursor.next = None
                else:
                    large_cursor.next = head
                    large_cursor = large_cursor.next
                    large_cursor.next = None
                head = temp

        if not small:
            return large
        if not large:
            return small
        if small and large:
            small_cursor.next = large
            return small
        return None

if __name__ == '__main__':
    # head = create_linked_list([1,4,3,2,5,2])
    head = create_linked_list([3,3,1,2,4])
    s = Solution()
    new_head = s.partition(head, 3)
    print_linked_list(new_head)



