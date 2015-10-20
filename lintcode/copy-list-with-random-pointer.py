#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/copy-list-with-random-pointer/

# Definition for singly-linked list with a random pointer.
# class RandomListNode:
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None
class Solution:
    # @param head: A RandomListNode
    # @return: A RandomListNode
    def copyRandomList(self, head):
        # write your code here
        # Copy nodes for 'next' pointer.
        has_random = False

        node = head
        while node:
            if node.random:
                has_random = True
            new_node = RandomListNode(node.label)
            new_node.next = node.next
            node.next = new_node
            node = new_node.next

        # Adjust nodes for 'random' pointer.
        if has_random:
            node = head
            while node:
                new_node = node.next
                if node.random:
                    new_node.random = node.random.next
                node = new_node.next

        # Split the copied list.
        node = head
        new_head = None
        cursor = None
        while node:
            new_node = node.next
            if not new_head:
                new_head = new_node
                cursor = new_head
            else:
                cursor.next = new_node
                cursor = new_node
            node.next = new_node.next
            new_node.next = None
            node = node.next

        return new_head
