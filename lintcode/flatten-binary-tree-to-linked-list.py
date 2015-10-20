#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/flatten-binary-tree-to-linked-list/

"""
Definition of TreeNode:
"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
class Solution:
    # @param root: a TreeNode, the root of the binary tree
    # @return: nothing
    def flatten(self, root):
        # write your code here
        if not root:
            return

        self.flatten(root.left)
        self.flatten(root.right)
        prev = None
        curs = root.left
        while curs:
            prev = curs
            curs = curs.right
        if prev:
            prev.right = root.right
            root.right = root.left
            root.left = None

if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(5)
    root.left.left = TreeNode(3)
    root.left.right = TreeNode(4)
    root.right.right = TreeNode(6)
    s = Solution()
    s.flatten(root)
    print root.val, root.right.val, root.right.right.val, root.right.right.right.val, root.right.right.right.right.val, root.right.right.right.right.right.val
