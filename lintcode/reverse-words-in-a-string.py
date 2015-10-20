#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/reverse-words-in-a-string/

class Solution:
    def simple_way(self, s):
        array = s.strip().split(' ')
        return ' '.join(array[::-1])

    # @param s : A string
    # @return : A string
    def reverseWords(self, s):
        # write your code here
        return self.simple_way(s)

if __name__ == '__main__':
    s = Solution()
    print s.reverseWords('the sky is blue')
