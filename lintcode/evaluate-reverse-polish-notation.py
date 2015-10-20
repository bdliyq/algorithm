#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/evaluate-reverse-polish-notation/

class Solution:
    # @param {string[]} tokens The Reverse Polish Notation
    # @return {int} the value
    def evalRPN(self, tokens):
        # Write your code here
        if len(tokens) == 0:
            return 0

        stack = []
        stack.append(int(tokens[0]))
        for s in tokens[1:]:
            if s == '+' or s == '-' or s == '*' or s == '/':
                y = stack.pop()
                x = stack.pop()
                if s == '+':
                    stack.append(x + y)
                elif s == '-':
                    stack.append(x - y)
                elif s == '*':
                    stack.append(x * y)
                else:
                    if (x < 0 and y > 0) or (x > 0 and y < 0):
                        stack.append(-1 * (abs(x) / abs(y)))
                    else:
                        stack.append((abs(x) / abs(y)))
            else:
                stack.append(int(s))

        return stack[0]

if __name__ == '__main__':
    s = Solution()
    # print s.evalRPN(["2", "1", "+", "3", "*"])
    # print s.evalRPN(["4", "13", "5", "/", "+"])
    print s.evalRPN(["10","6","9","3","+","-11","*","/","*","17","+","5","+"])
