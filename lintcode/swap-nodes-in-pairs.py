#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/swap-nodes-in-pairs/

from linked_list import *

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a ListNode
    def swapPairs(self, head):
        # Write your code here
        dummy1 = ListNode(0)
        dummy2 = ListNode(0)
        writer1 = dummy1
        writer2 = dummy2
        reader = head
        count = 0
        while reader:
            if count % 2 == 0:
                writer1.next = reader
                reader = reader.next
                writer1 = writer1.next
                writer1.next = None
            else:
                writer2.next = reader
                reader = reader.next
                writer2 = writer2.next
                writer2.next = None
            count += 1

        if count <= 1:
            return head
        dummy = ListNode(0)
        writer = dummy
        reader1 = dummy1.next
        reader2 = dummy2.next
        count = 0
        while reader1 and reader2:
            if count % 2 == 0:
                writer.next = reader2
                reader2 = reader2.next
                writer = writer.next
                writer.next = None
            else:
                writer.next = reader1
                reader1 = reader1.next
                writer = writer.next
                writer.next = None
            count += 1
        if reader1:
            writer.next = reader1
        if reader2:
            writer.next = reader2
        return dummy.next

if __name__ == '__main__':
    head = create_linked_list([1,2,3,4])
    head = create_linked_list([1,2])
    s = Solution()
    new_head = s.swapPairs(head)
    print_linked_list(new_head)






