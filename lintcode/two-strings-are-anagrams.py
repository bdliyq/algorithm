#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/two-strings-are-anagrams/

class Solution:
    """
    @param s: The first string
    @param b: The second string
    @return true or false
    """
    def anagram(self, s, t):
        # write your code here
        counter_dict = [0 for i in xrange(256)]
        for i in xrange(len(s)):
            counter_dict[ord(s[i])] += 1
        for j in xrange(len(t)):
            counter_dict[ord(t[j])] -= 1
        for c in counter_dict:
            if c != 0:
                return False
        return True

if __name__ == '__main__':
    s = Solution()
    print s.anagram('lint', 'intl')
