#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/longest-palindromic-substring/

class Solution:
    # @param {string} s input string
    # @return {string} the longest palindromic substring
    def longestPalindrome(self, s):
        # Write your code here
        result = ''

        # For odd palindrome.
        for i in xrange(len(s)):
            j = 1
            while i-j >= 0 and i+j <= len(s)-1 and s[i-j] == s[i+j]:
                j += 1
            if len(result) < 2*j-1:
                result = s[i-j+1:i+j]

        # For even palindrome.
        for i in xrange(len(s)):
            j = 0
            while i-j >= 0 and i+j+1 <=len(s)-1 and s[i-j] == s[i+j+1]:
                j += 1
            if j == 0:
                if len(result) < 1:
                    result = s[i]
            else:
                if len(result) < 2*j:
                    result = s[i-j+1:i+j+1]

        return result

if __name__ == '__main__':
    s = Solution()
    print s.longestPalindrome('abcdzdcab')
    print s.longestPalindrome('abcddcab')
    print s.longestPalindrome('abcd')
