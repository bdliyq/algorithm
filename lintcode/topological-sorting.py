#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/topological-sorting/

# Definition for a Directed graph node
# class DirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    """
    @param graph: A list of Directed graph node
    @return: A list of integer
    """
    def topSort(self, graph):
        # write your code here
        unvisited = set(graph)
        ans = []
        while unvisited:
            cur = unvisited.copy().pop()
            self.dfs(cur, unvisited, ans)
        return ans

    def dfs(self, cur, unvisited, ans):
        for nbr in cur.neighbors:
            if nbr in unvisited:
                self.dfs(nbr, unvisited, ans)
        ans.insert(0, cur)
        unvisited.remove(cur)
