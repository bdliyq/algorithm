#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/lowest-common-ancestor/

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
import copy
class Solution:
    """
    @param root: The root of the binary search tree.
    @param A and B: two nodes in a Binary.
    @return: Return the least common ancestor(LCA) of the two nodes.
    """
    def lowestCommonAncestor(self, root, A, B):
        # write your code here
        if not root:
            return None
        if root.val != A.val and root.val != B.val:
            left = self.lowestCommonAncestor(root.left, A, B)
            right = self.lowestCommonAncestor(root.right, A, B)
            if left and right:
                return root
            return left if left else right
        if root.val == A.val:
            return root
        if root.val == B.val:
            return root


