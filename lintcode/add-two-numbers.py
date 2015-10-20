#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/add-two-numbers/

from linked_list import *

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param l1: the first list
    # @param l2: the second list
    # @return: the sum list of l1 and l2
    def addLists(self, l1, l2):
        # write your code here
        dummy = ListNode(0)
        r1 = l1
        r2 = l2
        carry = 0
        w = dummy
        while r1 or r2 or carry > 0:
            i1, i2 = 0, 0
            if r1:
                i1 = r1.val
                r1 = r1.next
            if r2:
                i2 = r2.val
                r2 = r2.next
            ir = (i1 + i2 + carry) % 10
            carry = (i1 + i2 + carry) / 10
            node = ListNode(ir)
            w.next = node
            w = node
        return dummy.next

if __name__ == '__main__':
    s = Solution()
    head1 = create_linked_list([7,1,6])
    head2 = create_linked_list([5,9,3])
    headr = s.addLists(head1, head2)
    print_linked_list(headr)
