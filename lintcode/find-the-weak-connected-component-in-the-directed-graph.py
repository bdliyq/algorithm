#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/find-the-weak-connected-component-in-the-directed-graph/

# Definition for a directed graph node
class DirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []

class Solution:
    # @param {DirectedGraphNode[]} nodes a array of directed graph node
    # @return {int[][]} a connected set of a directed graph
    def connectedSet2(self, nodes):
        # Write your code here
        visited = set()
        # Create a parent-linked tree by hashtable for union find.
        # More basic knowledge about union find please refer to: http://blog.csdn.net/dm_vincent/article/details/7655764
        # BTW, TO the blog's author: please let me know if you do not want me to put your post's link here. I will delete it immediately I get your notice, and thanks for your brilliant blog. My email: leolyq@yahoo.com
        node_group = dict()

        for node in nodes:
            node_group[node.label] = node.label

        for node in nodes:
            stack = []
            stack.append(node)
            while stack:
                n = stack.pop()
                if n.label in visited:
                    continue
                visited.add(n.label)
                for nei in n.neighbors:
                    stack.append(nei)
                    id1 = node_group[nei.label]
                    id2 = node_group[n.label]
                    if id1 == id2:
                        continue
                    for the_node in nodes:
                        if node_group[the_node.label] == id2:
                            node_group[the_node.label] = id1

        results = dict()
        for kv in node_group.items():
            if results.has_key(kv[1]):
                results[kv[1]].add(kv[0])
            else:
                results[kv[1]] = set();
                results[kv[1]].add(kv[0])

        results_array = []
        for v in results.values():
            results_array.append(sorted(list(v)))

        return results_array

if __name__ == '__main__':
    nodeA = DirectedGraphNode('A')
    nodeB = DirectedGraphNode('B')
    nodeC = DirectedGraphNode('C')
    nodeD = DirectedGraphNode('D')
    nodeE = DirectedGraphNode('E')
    nodeF = DirectedGraphNode('F')
    nodeG = DirectedGraphNode('G')
    nodeH = DirectedGraphNode('H')
    nodeI = DirectedGraphNode('I')
    nodeA.neighbors.append(nodeB)
    nodeA.neighbors.append(nodeD)
    nodeB.neighbors.append(nodeD)
    nodeC.neighbors.append(nodeE)
    nodeF.neighbors.append(nodeE)
    nodeG.neighbors.append(nodeH)
    graph = [nodeA, nodeB, nodeC, nodeD, nodeE, nodeF, nodeH, nodeG, nodeI]

    s = Solution()
    print s.connectedSet2(graph)
