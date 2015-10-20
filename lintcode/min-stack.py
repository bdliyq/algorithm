#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/min-stack/

class MinStack(object):

    def __init__(self):
        # do some intialize if necessary
        self.data_stack = []
        self.min_stack = []

    def push(self, number):
        # write yout code here
        self.data_stack.append(number)
        if len(self.min_stack) == 0 or number < self.min_stack[-1]:
            self.min_stack.append(number)
        else:
            self.min_stack.append(self.min_stack[-1])

    def pop(self):
        # pop and return the top item in stack
        self.min_stack.pop()
        return self.data_stack.pop()

    def min(self):
        # return the minimum number in stack
        return self.min_stack[-1]

if __name__ == '__main__':
    s = MinStack()
    s.push(1)
    print s.pop()
    s.push(2)
    s.push(3)
    print s.min()
    s.push(1)
    print s.min()
