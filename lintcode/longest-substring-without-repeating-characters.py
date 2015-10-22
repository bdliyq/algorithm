#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/longest-substring-without-repeating-characters/

class Solution:
    # @param s: a string
    # @return: an integer
    def lengthOfLongestSubstring(self, s):
        # write your code here
        if len(s) == 0:
            return 0

        st = set()
        st.add(s[0])
        istart = 0
        iend = 1
        res = 1
        while iend < len(s):
            if s[iend] in st:
                while s[istart] != s[iend]:
                    st.remove(s[istart])
                    istart += 1
                istart += 1
            else:
                st.add(s[iend])
                res = max(res, iend - istart + 1)
            iend += 1
        return res



if __name__ == '__main__':
    s = Solution()
    print s.lengthOfLongestSubstring('abcabcbb')
    print s.lengthOfLongestSubstring('bbbbb')
