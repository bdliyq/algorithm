#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/segment-tree-query/

"""
Definition of SegmentTreeNode:
class SegmentTreeNode:
    def __init__(self, start, end, max):
        self.start, self.end, self.max = start, end, max
        self.left, self.right = None, None
"""

class Solution:
    # @param root, start, end: The root of segment tree and
    #                          an segment / interval
    # @return: The maximum number in the interval [start, end]
    def query(self, root, start, end):
        # write your code here
        if not root or start > end:
            return -1

        start = max(start, root.start)
        end = min(end, root.end)
        if root.start == start and root.end == end:
            return root.max

        mid = (root.start + root.end) / 2
        if start <= mid and end <= mid:
            return self.query(root.left, start, end)
        if start > mid and end > mid:
            return self.query(root.right, start, end)
        if start <= mid and end > mid:
            return max(self.query(root.left, start, mid), self.query(root.right, mid + 1, end))
        return -1

if __name__ == '__main__':
    s = Solution()
    print s.query(None, 0, 10)
