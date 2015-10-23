#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/unique-binary-search-trees-ii/

"""
Definition of TreeNode:
"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class Solution:
    def work_with_recursion(self, istart, iend):
        ans = []
        if istart > iend:
            return ans

        for i in xrange(istart, iend+1):
            for j in self.work_with_recursion(istart, i-1) or [None]:
                for k in self.work_with_recursion(i+1, iend) or [None]:
                    root = TreeNode(i)
                    root.left = j
                    root.right = k
                    ans.append(root)

        return ans

    # @paramn n: An integer
    # @return: A list of root
    def generateTrees(self, n):
        # write your code here
        if n == 0:
            return [[]]

        return self.work_with_recursion(1, n)

if __name__ == '__main__':
    s = Solution()
    trees = s.generateTrees(3)
