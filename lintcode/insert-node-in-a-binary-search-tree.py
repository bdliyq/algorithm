#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/insert-node-in-a-binary-search-tree/

"""
Definition of TreeNode:
"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
class Solution:
    """
    @param root: The root of the binary search tree.
    @param node: insert this node into the binary search tree.
    @return: The root of the new binary search tree.
    """
    def insertNode(self, root, node):
        # write your code here
        if not root:
            return node

        cursor = root
        while True:
            if not cursor:
                break
            if node.val == cursor.val:
                break
            elif node.val < cursor.val:
                if not cursor.left:
                    cursor.left = node
                    break
                else:
                    cursor = cursor.left
            elif node.val > cursor.val:
                if not cursor.right:
                    cursor.right = node
                    break
                else:
                    cursor = cursor.right
        return root

if __name__ == '__main__':
    root = TreeNode(2)
    root.left = TreeNode(1)
    root.right = TreeNode(4)
    root.right.left = TreeNode(3)

    s = Solution()
    s.insertNode(root, TreeNode(6))
