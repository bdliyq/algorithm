#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/valid-palindrome/

class Solution:
    def check(self, c):
        if c >= '0' and c <= '9':
            return True
        if c >= 'A' and c <= 'Z':
            return True
        return False

    # @param {string} s A string
    # @return {boolean} Whether the string is a valid palindrome
    def isPalindrome(self, s):
        # Write your code here
        if len(s) == 0:
            return True

        s_copy = s.upper()
        low = 0
        high = len(s) - 1
        while low < high:
            while low < high and not self.check(s_copy[low]):
                low += 1
            while low < high and not self.check(s_copy[high]):
                high -= 1
            if low < high:
                if s_copy[low] != s_copy[high]:
                    return False
                low += 1
                high -= 1

        return True

if __name__ == '__main__':
    s = Solution()
    print s.isPalindrome('A man, a plan, a canal: Panama')
    print s.isPalindrome(',.?')
    print s.isPalindrome(',.?a')
    print s.isPalindrome('1,.?a&*1')
    print s.isPalindrome('1a2')
