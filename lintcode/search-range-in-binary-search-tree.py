#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/search-range-in-binary-search-tree/

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
class Solution:
    """
    @param root: The root of the binary search tree.
    @param k1 and k2: range k1 to k2.
    @return: Return all keys that k1<=key<=k2 in ascending order.
    """
    def searchRange(self, root, k1, k2):
        # write your code here
        ans = []
        if not root:
            return ans
        if root.val < k1:
            ans.extend(self.searchRange(root.right, k1, k2))
        elif root.val > k2:
            ans.extend(self.searchRange(root.left, k1, k2))
        else:
            ans.append(root.val)
            ans.extend(self.searchRange(root.left, k1, k2))
            ans.extend(self.searchRange(root.right, k1, k2))
        return sorted(ans)
