#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/implement-queue-by-two-stacks/

class Queue:

    def __init__(self):
        self.stack1 = []
        self.stack2 = []

    def push(self, element):
        # write your code here
        self.stack1.append(element)

    def top(self):
        # write your code here
        # return the top element
        if self.stack2:
            return self.stack2[-1]
        else:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
            if self.stack2:
                return self.stack2[-1]
        return 0

    def pop(self):
        # write your code here
        # pop and return the top element
        if self.stack2:
            return self.stack2.pop()
        else:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
            if self.stack2:
                return self.stack2.pop()
        return 0

if __name__ == '__main__':
    q = Queue()
    q.push(1)
    print q.pop()
    q.push(2)
    q.push(3)
    print q.top()
    print q.pop()
