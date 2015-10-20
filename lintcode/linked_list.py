#!/usr/bin/env python
# encoding: utf-8

# Common utilities for linked-list.

class ListNode(object):
    def __init__(self, val, next=None):
        self.val = val
        self.next = next

def create_linked_list(elements):
    if len(elements) == 0:
        return None

    head = ListNode(elements[0])
    currp = head
    for e in elements[1:]:
        node = ListNode(e)
        currp.next = node
        currp = node

    return head

def print_linked_list(head):
    res = ''
    while head is not None:
        if len(res) > 0:
            res += '->'
        res += str(head.val)
        head = head.next

    print res
