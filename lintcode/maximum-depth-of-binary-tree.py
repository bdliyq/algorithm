#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/maximum-depth-of-binary-tree/

"""
Definition of TreeNode:
"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class Solution:
    """
    @param root: The root of binary tree.
    @return: An integer
    """
    def maxDepth(self, root):
        # write your code here
        if not root:
            return 0

        return max(1+self.maxDepth(root.left), 1+self.maxDepth(root.right))


if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(5)
    root.right.left.left = TreeNode(6)
    s = Solution()
    print s.maxDepth(root)
