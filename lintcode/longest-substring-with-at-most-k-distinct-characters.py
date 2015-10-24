#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/longest-substring-with-at-most-k-distinct-characters/

class Solution:
    # @param s : A string
    # @return : An integer
    def lengthOfLongestSubstringKDistinct(self, s, k):
        # write your code here
        if k == 0 or len(s) == 0:
            return 0

        subset = {}
        i = 0
        j = 0
        r = 0
        while i < len(s):
            if subset.has_key(s[i]):
                subset[s[i]] += 1
            else:
                while len(subset) == k:
                    subset[s[j]] -= 1
                    if subset[s[j]] == 0:
                        del subset[s[j]]
                    j += 1
                subset[s[i]] = 1
            r = max(i-j+1, r)
            i += 1
        return r

if __name__ == '__main__':
    s = Solution()
    print s.lengthOfLongestSubstringKDistinct('eceba', 3)
    print s.lengthOfLongestSubstringKDistinct('eceba', 1)
