#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/delete-digits/

class Solution:
    """
    @param A: A positive integer which has N digits, A is a string.
    @param k: Remove k digits.
    @return: A string
    """
    def DeleteDigits(self, A, k):
        # write you code here
        if len(A) <= k:
            return ''

        stack = []
        pop_count = 0
        i = 0
        while i < len(A):
            if not stack or stack[-1] <= A[i]:
                stack.append(A[i])
            else:
                if pop_count < k:
                    stack.pop()
                    pop_count += 1
                    i -= 1
                else:
                    stack.append(A[i])
            i += 1

        while pop_count < k:
            stack.pop()
            pop_count += 1

        ans = ''.join(stack).strip('0')
        return ans

if __name__ == '__main__':
    s = Solution()
    print s.DeleteDigits('178542', 4)
    print s.DeleteDigits('87654321', 2)
    print s.DeleteDigits('90249', 2)
