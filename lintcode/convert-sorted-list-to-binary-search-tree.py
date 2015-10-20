#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/convert-sorted-list-to-binary-search-tree/

"""
Definition of ListNode
class ListNode(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
class Solution:
    """
    @param head: The first node of linked list.
    @return: a tree node
    """
    def sortedListToBST(self, head):
        # write your code here
        if not head:
            return None
        if not head.next:
            return TreeNode(head.val)

        slow = head
        fast = head
        prev_slow = None
        while fast and fast.next:
            prev_slow = slow
            slow = slow.next
            fast = fast.next.next
        prev_slow.next = None
        node = TreeNode(slow.val)
        node.left = self.sortedListToBST(head)
        node.right = self.sortedListToBST(slow.next)
        return node


