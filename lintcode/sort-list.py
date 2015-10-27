#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/sort-list/

from linked_list import *

"""
Definition of ListNode
class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""
class Solution:
    def split_list(self, head):
        if not head or not head.next:
            return head

        slow = head
        fast = head.next
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        head1 = head
        head2 = slow.next
        slow.next = None

        return head1, head2

    def merge_list(self, head1, head2):
        dummy = ListNode(0)
        writer = dummy
        cursor1 = head1
        cursor2 = head2
        while cursor1 and cursor2:
            if cursor1.val < cursor2.val:
                writer.next = cursor1
                cursor1 = cursor1.next
                writer = writer.next
            else:
                writer.next = cursor2
                cursor2 = cursor2.next
                writer = writer.next
        if cursor1:
            writer.next = cursor1
        elif cursor2:
            writer.next = cursor2

        return dummy.next


    """
    @param head: The first node of the linked list.
    @return: You should return the head of the sorted linked list,
                  using constant space complexity.
    """
    def sortList(self, head):
        # write your code here
        if not head or not head.next:
            return head

        h1, h2 = self.split_list(head)
        head1 = self.sortList(h1)
        head2 = self.sortList(h2)

        return self.merge_list(head1, head2)

if __name__ == '__main__':
    head = ListNode(3)
    head.next = ListNode(2)
    head.next.next = ListNode(1)
    print_linked_list(head)
    s = Solution()
    new_head = s.sortList(head)
    print_linked_list(new_head)
