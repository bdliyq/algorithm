#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/binary-tree-maximum-path-sum/

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

import sys

class Solution:
    def dfs(self, root):
        if not root:
            return 0

        l, r = self.dfs(root.left), self.dfs(root.right)
        self.max_res = max(self.max_res, root.val + l + r)

        # dfs 方法需要返回包括root在内的左右子树中的任何一个分支，用于在上一行代码中的计算包含其父节点的最大值。
        return max(0, root.val + max(l, r))

    """
    @param root: The root of binary tree.
    @return: An integer
    """
    def maxPathSum(self, root):
        # write your code here
        self.max_res = -sys.maxint
        self.dfs(root)
        return self.max_res

