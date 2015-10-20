#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/clone-graph/

from undirected_graph import *

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def __init__(self):
        self.dict = {}

    def work_with_recursion(self, node):
        if not node:
            return None

        node_copy = None
        if self.dict.has_key(node):
            node_copy = self.dict[node]
        else:
            node_copy = UndirectedGraphNode(node.label)
            self.dict[node] = node_copy
            for n in node.neighbors:
                node_copy.neighbors.append(self.work_with_recursion(n))

        return node_copy

    def work_without_recursion(self, node):
        if not node:
            return None

        stack = []
        node_copy = UndirectedGraphNode(node.label)
        stack.append(node)
        self.dict[node] = node_copy

        while len(stack) > 0:
            old_node = stack.pop()
            new_node = self.dict[old_node]
            for n in old_node.neighbors:
                if self.dict.has_key(n):
                    new_node.neighbors.append(self.dict[n])
                else:
                    n_copy = UndirectedGraphNode(n.label)
                    new_node.neighbors.append(n_copy)
                    stack.append(n)
                    self.dict[n] = n_copy

        return node_copy


    def cloneGraph(self, node):
        # write your code here
        return self.work_with_recursion(node)
        # return self.work_without_recursion(node)

if __name__ == '__main__':
    node = create_undirected_graph('0,1,5#1,2,5#2,3#3,4,4#4,5,5#5')
    node_str = ''
    node_str += str(node.label)
    for n in node.neighbors:
        node_str += str(n.label)

    print node_str
    s = Solution()
    newnode = s.cloneGraph(node)

    node_str = ''
    node_str += str(newnode.label)
    for n in newnode.neighbors:
        node_str += str(n.label)
    print node_str
