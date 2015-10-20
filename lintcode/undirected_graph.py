#!/usr/bin/env python
# encoding: utf-8

# Definition for a undirected graph node.
class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []

def create_undirected_graph(info):
    node_dict = {}
    node = None
    node_infos = info.split('#')
    node_labels = node_infos[0].split(',')
    if node_dict.has_key(node_labels[0]):
        node = node_dict[node_labels[0]]
    else:
        node = UndirectedGraphNode(node_labels[0])

    for label in node_labels[1:]:
        neighbor = None
        if node_dict.has_key(label):
            neighbor = node_dict[label]
        else:
            neighbor = UndirectedGraphNode(label)
        node.neighbors.append(neighbor)

    for node_info in node_infos[1:]:
        node_labels = node_info.split(',')
        the_node = None
        if node_dict.has_key(node_labels[0]):
            the_node = node_dict[node_labels[0]]
        else:
            the_node = UndirectedGraphNode(node_labels[0])
        for label in node_labels[1:]:
            neighbor = None
            if node_dict.has_key(label):
                neighbor = node_dict[label]
            else:
                neighbor = UndirectedGraphNode(label)
            the_node.neighbors.append(neighbor)

    return node


def print_undirected_graph(node):
    res = ''

