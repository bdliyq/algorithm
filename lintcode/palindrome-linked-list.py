#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/palindrome-linked-list/

from linked_list import *

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param head, a ListNode
    # @return a boolean
    def isPalindrome(self, head):
        # Write your code here
        if not head or not head.next:
            return True

        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        if fast:
            slow = slow.next
        dummy = ListNode(0)
        while slow:
            next_slow = slow.next
            slow.next = dummy.next
            dummy.next = slow
            slow = next_slow

        reader1 = head
        reader2 = dummy.next
        while reader1 and reader2:
            if reader1.val != reader2.val:
                return False
            reader1 = reader1.next
            reader2 = reader2.next
        return True

if __name__ == '__main__':
    head = create_linked_list([1,2,1])
    head = create_linked_list([1,1])
    head = create_linked_list([1,2])
    s = Solution()
    print s.isPalindrome(head)



