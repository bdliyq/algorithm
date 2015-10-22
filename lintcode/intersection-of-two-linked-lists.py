#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/intersection-of-two-linked-lists/

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param headA: the first list
    # @param headB: the second list
    # @return: a ListNode
    def getIntersectionNode(self, headA, headB):
        # Write your code here
        if not headA or not headB:
            return None

        cursor = headA
        while cursor.next:
            cursor = cursor.next
        cursor.next = headB

        cursor = headA
        fast = headA
        while fast and fast.next:
            cursor = cursor.next
            fast = fast.next.next
            if cursor == fast:
                break
        if cursor == fast:
            another_cursor = headA
            while cursor != another_cursor:
                cursor = cursor.next
                another_cursor = another_cursor.next
            return cursor
        return None

