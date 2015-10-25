#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/interval-minimum-number/

"""
Definition of Interval.
"""

import sys

class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end

class SegmentNode(object):
    def __init__(self, start, end, minimum):
        self.start = start
        self.end = end
        self.minimum = minimum
        self.left = self.right = None

class Solution:
    def build(self, start, end, A):
        if start > end:
            return None

        root = SegmentNode(start, end, sys.maxint)
        if start == end:
            root.minimum = A[start]
        else:
            mid = (start + end) / 2
            root.left = self.build(start, mid, A)
            root.right = self.build(mid+1, end, A)
            root.minimum = min(root.left.minimum, root.right.minimum)

        return root

    def query(self, start, end, root):
        if start == root.start and end == root.end:
            return root.minimum

        mid = (root.start + root.end) / 2
        left_min, right_min = sys.maxint, sys.maxint
        if start <= mid:
            if end <= mid:
                left_min = self.query(start, end, root.left)
            else:
                left_min = self.query(start, mid, root.left)
        if mid < end:
            if mid < start:
                right_min = self.query(start, end, root.right)
            else:
                right_min = self.query(mid+1, end, root.right)

        return min(left_min, right_min)

    """
    @param A, queries: Given an integer array and an Interval list
                       The ith query is [queries[i-1].start, queries[i-1].end]
    @return: The result list
    """
    def intervalMinNumber(self, A, queries):
        # write your code here
        root = self.build(0, len(A)-1, A)
        ans = []
        for q in queries:
            ans.append(self.query(q.start, q.end, root))
        return ans

