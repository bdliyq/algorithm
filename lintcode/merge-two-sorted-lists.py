#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/merge-two-sorted-lists/

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
    @param two ListNodes
    @return a ListNode
    """
    def mergeTwoLists(self, l1, l2):
        # write your code here
        if not l1 and not l2:
            return None
        if not l1:
            return l2
        if not l2:
            return l1

        head = None
        cursor = None
        while l1 and l2:
            if l1.val < l2.val:
                if not head:
                    head = l1
                    cursor = head
                else:
                    cursor.next = l1
                    cursor = l1  # cursor = cursor.next
                l1 = l1.next
            else:
                if not head:
                    head = l2
                    cursor = head
                else:
                    cursor.next = l2
                    cursor = l2  # cursor = cursor.next
                l2 = l2.next

        if l1:
            cursor.next = l1
        elif l2:
            cursor.next = l2

        return head

if __name__ == '__main__':
    head1 = create_linked_list([1,3,5,7])
    head2 = create_linked_list([2,4,6,8])
    s = Solution()
    answer = s.mergeTwoLists(head1, head2)
    print_linked_list(answer)



