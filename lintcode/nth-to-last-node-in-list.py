#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/nth-to-last-node-in-list/

"""
Definition of ListNode
class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""
class Solution:
    """
    @param head: The first node of linked list.
    @param n: An integer.
    @return: Nth to last node of a singly linked list.
    """
    def nthToLast(self, head, n):
        # write your code here
        p = head
        for i in xrange(n):
            p = p.next

        q = head
        while p:
            q = q.next
            p = p.next
        return q

