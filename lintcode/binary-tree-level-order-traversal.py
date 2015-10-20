#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/binary-tree-level-order-traversal/

"""
Definition of TreeNode:
"""
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class Solution:
    """
    @param root: The root of binary tree.
    @return: Level order in a list of lists of integers
    """
    def levelOrder(self, root):
        # write your code here
        if not root:
            return []

        result = [[]]
        queue = [root]
        current_level_count = 1
        next_level_count = 0
        while queue:
            node = queue.pop(0)
            current_level_count -= 1
            result[-1].append(node.val)
            if node.left:
                queue.append(node.left)
                next_level_count += 1
            if node.right:
                queue.append(node.right)
                next_level_count += 1
            if current_level_count == 0:
                if next_level_count > 0:
                    result.append([])
                current_level_count, next_level_count = next_level_count, current_level_count
        return result

if __name__ == '__main__':
    s = Solution()
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    print s.levelOrder(root)
