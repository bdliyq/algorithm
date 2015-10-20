#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/segment-tree-query-ii/

"""
Definition of SegmentTreeNode:
class SegmentTreeNode:
    def __init__(self, start, end, count):
        self.start, self.end, self.count = start, end, count
        self.left, self.right = None, None
"""

class Solution:
    # @param root, start, end: The root of segment tree and
    #                          an segment / interval
    # @return: The count number in the interval [start, end]
    def query(self, root, start, end):
        # write your code here
        if not root or start > end:
            return 0

        start = max(start, root.start)
        end = min(end, root.end)
        if root.start == start and root.end == end:
            return root.count

        count = 0
        mid = (root.start + root.end) / 2
        if start <= mid and end <= mid:
            count += self.query(root.left, start, end)
        elif start > mid and end > mid:
            count += self.query(root.right, start, end)
        elif start <= mid and end > mid:
            count += self.query(root.left, start, mid) + self.query(root.right, mid + 1, end)
        else:
            return 0

        return count



