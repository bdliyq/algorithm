#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/binary-tree-preorder-traversal/

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
        result.append(root.val)
        self.work_with_recursion(root.left, result)
        self.work_with_recursion(root.right, result)

    def work_without_recursion(self, root):
        result = []
        if not root:
            return result

        stack = []
        stack.append(root)
        while stack:
            node = stack.pop()
            result.append(node.val)
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)

        return result

    """
    @param root: The root of binary tree.
    @return: Preorder in ArrayList which contains node values.
    """
    def preorderTraversal(self, root):
        # write your code here
        return self.work_without_recursion(root)
        # result = []
        # self.work_with_recursion(root, result)
        # return result

if __name__ == '__main__':
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.right = TreeNode(3)
    s = Solution()
    print s.preorderTraversal(root)
