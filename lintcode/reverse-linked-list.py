#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/reverse-linked-list/

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
    @param head: The first node of the linked list.
    @return: You should return the head of the reversed linked list.
                  Reverse it in-place.
    """
    def reverse(self, head):
        # write your code here
        dummy = ListNode(0)
        reader = head
        while reader:
            temp = reader.next
            reader.next = dummy.next
            dummy.next = reader
            reader = temp
        return dummy.next

if __name__ == '__main__':
    s = Solution()
    head = create_linked_list([1,2,3])
    new_head = s.reverse(head)
    print_linked_list(new_head)
