#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/rehashing/

"""
Definition of ListNode
class ListNode(object):

    def __init__(self, val, next=None):
        self.val = val
        self.next = next
"""
class Solution:
    """
    @param hashTable: A list of The first node of linked list
    @return: A list of The first node of linked list which have twice size
    """
    def rehashing(self, hashTable):
        # write your code here
        new_hash_table = [None for i in xrange(2*len(hashTable))]
        for i in xrange(len(hashTable)):
            if hashTable[i]:
                node = hashTable[i]
                while node:
                    idx = node.val % len(new_hash_table)
                    new_node = new_hash_table[idx]
                    if not new_node:
                        new_node = ListNode(node.val)
                        new_hash_table[idx] = new_node
                    else:
                        while new_node.next:
                            new_node = new_node.next
                        new_node.next = ListNode(node.val)
                    node = node.next
        return new_hash_table

