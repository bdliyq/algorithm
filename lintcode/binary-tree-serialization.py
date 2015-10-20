#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/binary-tree-serialization/

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

class Solution:
    '''
    @param root: An object of TreeNode, denote the root of the binary tree.
    This method will be invoked first, you should design your own algorithm
    to serialize a binary tree which denote by a root node to a string which
    can be easily deserialized by your own "deserialize" method later.
    '''
    def serialize(self, root):
        # write your code here
        if not root:
            return ''

        result = []
        queue = []
        queue.append(root)
        while len(queue) > 0 and queue.count(None) != len(queue):
            node = queue.pop(0)
            if not node:
                result.append('#')
                queue.append(None)
                queue.append(None)
            else:
                result.append(str(node.val))
                queue.append(node.left)
                queue.append(node.right)

        return ' '.join(result)

    '''
    @param data: A string serialized by your serialize method.
    This method will be invoked second, the argument data is what exactly
    you serialized at method "serialize", that means the data is not given by
    system, it's given by your own serialize method. So the format of data is
    designed by yourself, and deserialize it here as you serialize it in
    "serialize" method.
    '''
    def deserialize(self, data):
        # write your code here
        if len(data) == 0:
            return None

        array = [TreeNode(data[0])]
        data_array = data.split(' ')

        for i in xrange(1, len(data_array)):
            if data_array[i] == '#':
                array.append(None)
                continue
            else:
                node = TreeNode(int(data_array[i]))
                array.append(node)
                if i % 2 == 1:
                    array[(i-1)/2].left = node
                else:
                    array[(i-2)/2].right = node

        return array[0]

if __name__ == '__main__':
    node = TreeNode(1)
    node.left = TreeNode(2)
    node.right = TreeNode(3)
    node.left.left = TreeNode(11)
    node.right.left = TreeNode(4)
    node.right.right = TreeNode(5)
    node.right.left.left = TreeNode(6)
    node.right.left.right = TreeNode(7)
    node.right.right.right = TreeNode(10)
    node.right.left.right.left = TreeNode(8)
    node.right.left.right.right = TreeNode(9)
    node.right.left.right.left.left = TreeNode(12)
    node.right.left.right.left.right = TreeNode(13)
    node.right.left.right.left.right.right = TreeNode(14)

    node.left.left = TreeNode(3)
    node.left.left.left = TreeNode(4)
    s = Solution()
    data = s.serialize(node)
    print data
    s.deserialize(data)
