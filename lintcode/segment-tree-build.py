#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/segment-tree-build/

"""
Definition of SegmentTreeNode:
class SegmentTreeNode:
    def __init__(self, start, end):
        self.start, self.end = start, end
        self.left, self.right = None, None
"""

class Solution:
    # @param start, end: Denote an segment / interval
    # @return: The root of Segment Tree
    def build(self, start, end):
        # write your code here
        if start > end:
            return None

        if start == end:
            return SegmentTreeNode(start, end)

        node = SegmentTreeNode(start, end)
        node.left = self.build(start, (start+end) / 2)
        node.right = self.build((start+end) / 2 + 1, end)

        return node

if __name__ == '__main__':
    s = Solution()
    s.build(0,5)
