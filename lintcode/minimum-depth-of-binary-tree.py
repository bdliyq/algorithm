#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/minimum-depth-of-binary-tree/

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
    def minDepth(self, root):
        # write your code here
        if not root:
            return 0

        if root.left and root.right:
            return min(1+self.minDepth(root.left), 1+self.minDepth(root.right))
        elif root.left and not root.right:
            return 1+self.minDepth(root.left)
        elif not root.left and root.right:
            return 1+self.minDepth(root.right)
        else:
            return 1

if __name__ == '__main__':
    root = TreeNode(1)
    root.right = TreeNode(3)
    root.right.left = TreeNode(4)
    root.right.right = TreeNode(5)
    root.right.left.left = TreeNode(6)
    s = Solution()
    print s.minDepth(root)
