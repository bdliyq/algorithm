#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/binary-tree-inorder-traversal/

"""
Definition of TreeNode:
"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class Solution:
    def work_with_recursion(self, root, result):
        if not root:
            return

        self.work_with_recursion(root.left, result)
        result.append(root.val)
        self.work_with_recursion(root.right, result)

    def work_without_recursion(self, root):
        result = []
        if not root:
            return result

        stack = []
        node = root
        while node or stack:
            if node:
                stack.append(node)
                node = node.left
            else:
                node = stack.pop()
                result.append(node.val)
                node = node.right

        return result

    """
    @param root: The root of binary tree.
    @return: Inorder in ArrayList which contains node values.
    """
    def inorderTraversal(self, root):
        # write your code here
        # return self.work_without_recursion(root)
        result = []
        self.work_with_recursion(root, result)
        return result

if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    s = Solution()
    print s.inorderTraversal(root)
