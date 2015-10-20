#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/merge-k-sorted-lists/

from linked_list import *
import heapq
import sys

class Solution:
    """
    @param lists: a list of ListNode
    @return: The head of one sorted list.
    """
    def mergeKLists(self, lists):
        # write your code here
        heap = []
        heapq.heapify(heap)
        for l in lists:
            if l is not None:
                heapq.heappush(heap, (l.val, l))

        if len(heap) == 0:
            return None
        if len(heap) == 1:
            val, node = heapq.heappop(heap)
            return node

        head = None
        p = None
        while len(heap) > 1:
            val, node = heapq.heappop(heap)
            nextnode = node.next
            node.next = None
            if not head:
                head = node
                p = head
            else:
                p.next = node
                p = node

            if nextnode is not None:
                heapq.heappush(heap, (nextnode.val, nextnode))

        if len(heap):
            val, node = heapq.heappop(heap)
            if not head:
                head = node
            else:
                p.next = node

        return head

if __name__ == '__main__':
    head1 = create_linked_list([2,4])
    head2 = create_linked_list([])
    head3 = create_linked_list([-1])
    lists = [head1, head2, head3]
    s = Solution()
    head = s.mergeKLists(lists)
    print_linked_list(head)

