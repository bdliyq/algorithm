#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/convert-expression-to-reverse-polish-notation/

class Solution:
    def pri(self, expression):
        if expression in ['+', '-']:
            return 1
        elif expression in ['*', '/']:
            return 2
        return 0

    # @param expression: A string list
    # @return: The Reverse Polish notation of this expression
    def convertToRPN(self, expression):
        # write your code here
        if not expression:
            return []

        ans = []
        stack = []
        for e in expression:
            if e.isdigit():
                ans.append(e)
            elif e == '(':
                stack.append(e)
            elif e == ')':
                while stack and stack[-1] != '(':
                    ans.append(stack.pop())
                stack.pop()
            else:
                while stack and self.pri(e) <= self.pri(stack[-1]):
                    ans.append(stack.pop())
                stack.append(e)

        while stack:
            ans.append(stack.pop())

        return ans
