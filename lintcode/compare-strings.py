#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/compare-strings/

class Solution:
    """
    @param A : A string includes Upper Case letters
    @param B : A string includes Upper Case letters
    @return :  if string A contains all of the characters in B return True else return False
    """
    def compareStrings(self, A, B):
        # write your code here
        d = {}
        for c in A:
            if d.has_key(c):
                d[c] += 1
            else:
                d[c] = 1

        for c in B:
            if d.has_key(c):
                d[c] -= 1
                if d[c] <= 0:
                    del d[c]
            else:
                return False
        return True


if __name__ == '__main__':
    s = Solution()
    print s.compareStrings('ABCD', 'ABD')
    print s.compareStrings('ABCD', 'ABE')
    print s.compareStrings('ABCDEFG', 'ACC')
