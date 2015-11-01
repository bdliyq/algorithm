#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/validate-binary-search-tree/

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

import sys
class Solution:
    def helper(self, root, min_val, max_val):
        if not root:
            return True

        if root.val > min_val and root.val < max_val:
            return self.helper(root.left, min_val, root.val) and self.helper(root.right, root.val, max_val)

        return False

    """
    @param root: The root of binary tree.
    @return: True if the binary tree is BST, or false
    """
    def isValidBST(self, root):
        # write your code here
        return self.helper(root, -sys.maxint, sys.maxint)

