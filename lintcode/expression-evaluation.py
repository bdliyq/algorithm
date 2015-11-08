#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/expression-evaluation/

class Solution:
    def pri(self, expression):
        if expression in ['+', '-']:
            return 1
        if expression in ['*', '/']:
            return 2
        return 0

    def convertToRPN(self, expression):
        if not expression:
            return []

        res = []
        stack = []
        for e in expression:
            if e.isdigit():
                res.append(e)
            elif e == '(':
                stack.append(e)
            elif e == ')':
                while stack and stack[-1] != '(':
                    res.append(stack.pop())
                stack.pop()
            else:
                while stack and self.pri(e) <= self.pri(stack[-1]):
                    res.append(stack.pop())
                stack.append(e)
        while stack:
            res.append(stack.pop())

        return res

    def calculate(self, expression):
        if not expression:
            return 0

        stack = []
        for e in expression:
            if e.isdigit():
                stack.append(int(e))
            else:
                right = stack.pop()
                left = stack.pop()
                res = 0
                if e == '+':
                    res = left + right
                elif e == '-':
                    res = left - right
                elif e == '*':
                    res = left * right
                else:
                    res = left / right
                stack.append(res)
        return stack[0]

    # @param expression: a list of strings;
    # @return: an integer
    def evaluateExpression(self, expression):
        # write your code here
        return self.calculate(self.convertToRPN(expression))

if __name__ == '__main__':
    s = Solution()
    print s.evaluateExpression(["(","(","(","(","(",")",")",")",")",")"])
    print s.evaluateExpression([
        "2", "*", "6", "-", "(",
        "23", "+", "7", ")", "/",
        "(", "1", "+", "2", ")"
        ])
