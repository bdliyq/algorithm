#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/construct-binary-tree-from-preorder-and-inorder-traversal/

"""
Definition of TreeNode:
"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class Solution:
    """
    @param preorder : A list of integers that preorder traversal of a tree
    @param inorder : A list of integers that inorder traversal of a tree
    @return : Root of a tree
    """
    def buildTree(self, preorder, inorder):
        # write your code here
        if len(preorder) == 0:
            return None

        root = TreeNode(preorder[0])
        for i in xrange(len(inorder)):
            if inorder[i] == preorder[0]:
                break

        inorder_left = inorder[:i]
        inorder_right = inorder[i+1:]
        preorder_left = preorder[1:i+1]
        preorder_right = preorder[i+1:]

        root.left = self.buildTree(preorder_left, inorder_left)
        root.right = self.buildTree(preorder_right, inorder_right)

        return root

if __name__ == '__main__':
    s = Solution()
    root = s.buildTree([2,1,3], [1,2,3])
    print root.val,root.left.val,root.right.val
