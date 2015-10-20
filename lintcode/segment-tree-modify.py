#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/segment-tree-modify/

"""
Definition of SegmentTreeNode:
class SegmentTreeNode:
    def __init__(self, start, end, max):
        self.start, self.end, self.max = start, end, max
        self.left, self.right = None, None
"""

class Solution:
    """
    @param root, index, value: The root of segment tree and
    @ change the node's value with [index, index] to the new given value
    @return: nothing
    """
    def modify(self, root, index, value):
        # write your code here
        if not root or index > root.end or index < root.start:
            return

        if root.start == index and root.end == index:
            root.max = value
        else:
            mid = (root.start + root.end) / 2
            if index <= mid:
                self.modify(root.left, index, value)
            else:
                self.modify(root.right, index, value)
            root.max = max(root.left.max, root.right.max)
