#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/find-the-connected-component-in-the-undirected-graph/

# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    # @param {UndirectedGraphNode[]} nodes a array of undirected graph node
    # @return {int[][]} a connected set of a undirected graph
    def connectedSet(self, nodes):
        # Write your code here
        if len(nodes) == 0:
            return [[]]

        visited = set()
        stack = []
        result = []

        for node in nodes:
            stack.append(node)
            path = []
            while stack:
                the_node = stack.pop()
                if the_node in visited:
                    continue
                path.append(the_node.label)
                visited.add(the_node)
                for neighbor in the_node.neighbors:
                    stack.append(neighbor)
            if path:
                result.append(sorted(path))

        return result
