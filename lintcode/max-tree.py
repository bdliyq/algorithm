#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/max-tree/

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
class Solution:
    # @param A: Given an integer array with no duplicates.
    # @return: The root of max tree.
    def maxTree(self, A):
        # write your code here
        if len(A) == 0:
            return None

        stack = []
        stack.append(TreeNode(A[0]))
        for i in xrange(1, len(A)):
            if A[i] <= stack[-1].val:
                stack.append(TreeNode(A[i]))
            else:
                n1 = stack.pop()
                while stack and stack[-1].val < A[i]:
                    n2 = stack.pop()
                    n2.right = n1
                    n1 = n2
                node = TreeNode(A[i])
                node.left = n1
                stack.append(node)

        root = stack.pop()
        while stack:
            node = stack.pop()
            node.right = root
            root = node

        return root



