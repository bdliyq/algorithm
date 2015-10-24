#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/count-of-smaller-number/

import bisect

class SegmentNode(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
        self.value = 0
        self.left = self.right = None

    def to_string(self):
        print self.start, self.end, self.value

class Solution:
    def create_helper(self, root, e):
        node = root
        while True:
            node.value += 1
            if node.start == node.end and node.start == e:
                break

            mid = (node.start + node.end) / 2
            if e > mid:
                if not node.right:
                    node.right = SegmentNode(mid+1, node.end)
                node = node.right
            else:
                if not node.left:
                    node.left = SegmentNode(node.start, mid)
                node = node.left

    def create_segment_tree(self, A):
        if len(A) == 0:
            return None

        self.min_ele = min(A)
        self.max_ele = max(A)
        root = SegmentNode(self.min_ele, self.max_ele)
        for i in xrange(len(A)):
            self.create_helper(root, A[i])
        return root

    def query_helper(self, root, start, end):
        if not root or start > end:
            return 0
        if root.start == start and root.end == end:
            return root.value

        count = 0
        mid = (root.start + root.end) / 2
        if start <= mid and end <= mid:
            count += self.query_helper(root.left, start, end)
        elif start > mid and end > mid:
            count += self.query_helper(root.right, start, end)
        elif start <= mid and end > mid:
            count += self.query_helper(root.left, start, mid) + self.query_helper(root.right, mid+1, end)

        return count

    def query_segment_tree(self, A, root, e):
        return self.query_helper(root, self.min_ele, e) - A.count(e)

    def work_with_segment_tree(self, A, queries):
        if len(queries) == 0:
            return []

        tree = self.create_segment_tree(A)

        res = []
        for q in queries:
            res.append(self.query_segment_tree(A, tree, q))
        return res

    def work_with_bisect(self, A, queries):
        A.sort()
        res = []
        for q in queries:
            res.append(bisect.bisect_left(A,q))
        return res

    """
    @param A: A list of integer
    @return: The number of element in the array that
             are smaller that the given integer
    """
    def countOfSmallerNumber(self, A, queries):
        # write your code here
        return self.work_with_bisect(A, queries)

if __name__ == '__main__':
    s = Solution()
    print s.countOfSmallerNumber([1,2,7,8,5], [1,8,5])
