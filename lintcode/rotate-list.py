#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/rotate-list/

from linked_list import *

class Solution:
    # @param head: the list
    # @param k: rotate to the right k places
    # @return: the list after rotation
    def rotateRight(self, head, k):
        # write your code here
        count = 0
        p = head
        tail = None
        while p:
            count += 1
            tail = p
            p = p.next
        if count <= 1:
            return head

        k = k % count
        if k == 0:
            return head

        p = None
        i = 0
        while i < count - k:
            if not p:
                p = head
            else:
                p = p.next
            i += 1

        tail.next = head
        head = p.next
        p.next = None
        return head




