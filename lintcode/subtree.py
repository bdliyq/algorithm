#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/subtree/

"""
Definition of TreeNode:
"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
class Solution:
    def check_sametree(self, t1, t2):
        if not t1 and not t2:
            return True
        if (not t1 and t2) or (t1 and not t2) or (t1.val != t2.val):
            return False
        return self.check_sametree(t1.left, t2.left) and self.check_sametree(t1.right, t2.right)

    # @param T1, T2: The roots of binary tree.
    # @return: True if T2 is a subtree of T1, or false.
    def isSubtree(self, T1, T2):
        # write your code here
        if not T2:
            return True
        if not T1 and T2:
            return False

        queue = []
        queue.append(T1)
        while queue:
            node = queue.pop(0)
            if self.check_sametree(node, T2):
                return True
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)

        return False

if __name__ == '__main__':
    root1 = TreeNode(1)
    root1.left = TreeNode(2)
    root1.right = TreeNode(3)
    root1.right.left = TreeNode(4)

    root2 = TreeNode(3)
    root2.left = TreeNode(4)

    root3 = TreeNode(3)
    root3.right = TreeNode(4)

    s = Solution()
    print s.isSubtree(root1, root2)
    print s.isSubtree(root1, root3)
    print s.isSubtree(root1, None)
