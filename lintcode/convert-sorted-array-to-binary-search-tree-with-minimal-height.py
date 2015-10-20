#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/convert-sorted-array-to-binary-search-tree-with-minimal-height/

"""
Definition of TreeNode:
"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class Solution:
    def work_with_recursion(self, array):
        if len(array) == 0:
            return

        mid = len(array) / 2
        root = TreeNode(array[mid])
        root.left = self.work_with_recursion(array[:mid])
        root.right = self.work_with_recursion(array[mid+1:])
        return root

    """
    @param A: a list of integer
    @return: a tree node
    """
    def sortedArrayToBST(self, A):
        # write your code here
        return self.work_with_recursion(A)

if __name__ == '__main__':
    s = Solution()
    root = s.sortedArrayToBST([1,2,3,4,5,6,7])
    print root.val,root.left.val,root.right.val,root.left.left.val,root.left.right.val,root.right.left.val,root.right.right.val

