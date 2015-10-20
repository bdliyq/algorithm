#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/remove-duplicates-from-sorted-list/

from linked_list import *

class Solution:
    """
    @param head: A ListNode
    @return: A ListNode
    """
    def deleteDuplicates(self, head):
        # write your code here
        if not head or not head.next:
            return head

        prevp = head
        nextp = head.next

        while nextp is not None:
            while nextp is not None and prevp.val == nextp.val:
                nextp = nextp.next

            prevp.next = nextp
            prevp = nextp
            if nextp is not None:
                nextp = nextp.next

        return head

if __name__ == '__main__':
    head = create_linked_list([1,1,2,3,3])
    s = Solution()
    newhead = s.deleteDuplicates(head)
    print_linked_list(newhead)
