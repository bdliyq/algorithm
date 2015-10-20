#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/remove-duplicates-from-sorted-list-ii/

from linked_list import *

"""
Definition of ListNode
class ListNode(object):
    def __init__(alf, val, next=None):
        self.val = val
        self.next = next
"""
class Solution:
    """
    @param head: A ListNode
    @return: A ListNode
    """
    def deleteDuplicates(self, head):
        # write your code here
        if not head or not head.next:
            return head

        new_head = None
        writer = None
        reader_slow = head
        reader_fast = head.next
        while reader_fast:
            old_reader_slow = reader_slow
            while reader_fast and reader_slow.val == reader_fast.val:
                reader_slow = reader_fast
                reader_fast = reader_fast.next

            if old_reader_slow == reader_slow:
                if not new_head:
                    new_head = reader_slow
                    writer = new_head
                else:
                    writer.next = reader_slow
                    writer = reader_slow

            if reader_fast:
                reader_slow = reader_fast
                reader_fast = reader_fast.next
                if not reader_fast:
                    writer.next = reader_slow
                    writer = writer.next

            if writer:
                writer.next = None

        return new_head

if __name__ == '__main__':
    s = Solution()
    head = create_linked_list([1,2,3,3,4,4,5])
    new_head = s.deleteDuplicates(head)
    print_linked_list(new_head)
    head = create_linked_list([2,3,4,4,4])
    new_head = s.deleteDuplicates(head)
    print_linked_list(new_head)
    head = create_linked_list([1,1,1])
    new_head = s.deleteDuplicates(head)
    print_linked_list(new_head)

