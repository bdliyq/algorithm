#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/construct-binary-tree-from-inorder-and-postorder-traversal/

"""
Definition of TreeNode:
"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class Solution:
    def helper_func(self, inorder, reverse_postorder):
        if len(inorder) == 0:
            return None

        root = TreeNode(reverse_postorder[0])
        for i in xrange(len(inorder)):
            if inorder[i] == reverse_postorder[0]:
                break

        inorder_left = inorder[:i]
        inorder_right = inorder[i+1:]
        reverse_postorder_left = reverse_postorder[len(reverse_postorder)-i:]
        reverse_postorder_right = reverse_postorder[1:len(reverse_postorder)-i]

        root.left = self.helper_func(inorder_left, reverse_postorder_left)
        root.right = self.helper_func(inorder_right, reverse_postorder_right)

        return root

    """
    @param inorder : A list of integers that inorder traversal of a tree
    @param postorder : A list of integers that postorder traversal of a tree
    @return : Root of a tree
    """
    def buildTree(self, inorder, postorder):
        # write your code here
        return self.helper_func(inorder, postorder[::-1])

if __name__ == '__main__':
    s = Solution()
    root = s.buildTree([1,2], [2,1])
    print root.val,root.right.val

