#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/remove-linked-list-elements/

from linked_list import *

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @param val, an integer
    # @return a ListNode
    def removeElements(self, head, val):
        # Write your code here
        dummy = ListNode(0)
        writer = dummy
        reader = head
        while reader:
            if reader.val != val:
                writer.next = reader
                writer = reader
                reader = reader.next
                writer.next = None
            else:
                reader = reader.next
        return dummy.next

if __name__ == '__main__':
    head = create_linked_list([1,2,3,3,4,5,3])
    s = Solution()
    new_head = s.removeElements(head, 3)
    print_linked_list(new_head)

