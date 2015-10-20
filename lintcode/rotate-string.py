#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/rotate-string/

class Solution:
    def rotate(self, s, start, end):
        low, high = start, end
        while low < high:
            s[low], s[high] = s[high], s[low]
            low += 1
            high -= 1

    # @param s: a list of char
    # @param offset: an integer
    # @return: nothing
    def rotateString(self, s, offset):
        # write you code here
        if len(s) <= 1:
            return

        offset %= len(s)
        self.rotate(s, 0, len(s) - 1)
        self.rotate(s, 0, offset - 1)
        self.rotate(s, offset, len(s) - 1)


if __name__ == '__main__':
    s = Solution()
    array = list(str('abcdefg'))
    s.rotateString(array, 2)
    print array
