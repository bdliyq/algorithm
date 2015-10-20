#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/unique-characters/

class Solution:
    # @param s: a string
    # @return: a boolean
    def isUnique(self, str):
        # write your code here
        ascii_array = [False for i in xrange(256)]
        for c in str:
            if ascii_array[ord(c)]:
                return False
            ascii_array[ord(c)] = True
        return True

if __name__ == '__main__':
    s = Solution()
    print s.isUnique('')
    print s.isUnique('abc')
    print s.isUnique('aab')
