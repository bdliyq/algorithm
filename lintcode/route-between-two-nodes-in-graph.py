#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/route-between-two-nodes-in-graph/

# Definition for a Directed graph node
# class DirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    """
    @param graph: A list of Directed graph node
    @param s: the starting Directed graph node
    @param t: the terminal Directed graph node
    @return: a boolean value
    """
    def hasRoute(self, graph, s, t):
        # write your code here
        queue = []
        for node in graph:
            if node.label == s.label:
                queue.append(node)
                break

        while queue:
            node = queue.pop()
            if node.label == t.label:
                return True
            for nei in node.neighbors:
                queue.append(nei)

        return False


