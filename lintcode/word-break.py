#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/word-break/

class Solution:
    # @param s: A string s
    # @param dict: A dictionary of words dict

    # def wordBreak(self, s, dict):
    #     # write your code here
    #     middle_pos = [0]
    #     for index in xrange(len(s)):
    #         for pos in middle_pos:
    #             if dict.has_key(s[pos:index+1]):
    #                 middle_pos.append(index+1)
    #                 break
    #     return (len(s) > 0 or len(dict) == 0) and middle_pos[-1] == len(s)

    def get_min_and_max_len(self, dict):
        min_len = 0
        max_len = 0
        for k, v in dict.items():
            if min_len == 0:
                min_len = len(k)
            if max_len == 0:
                max_len = len(k)
            min_len = min(min_len, len(k))
            max_len = max(max_len, len(k))
        return min_len, max_len

    def wordBreak(self, s, dict):
        if len(s) == 0 and len(dict) == 0:
            return True

        min_len, max_len = self.get_min_and_max_len(dict)

        stack = [0]
        while len(stack) > 0:
            pos = stack.pop()
            for i in xrange(min_len, max_len+1):
                if pos + i > len(s):
                    break
                if dict.has_key(s[pos:pos+i]):
                    if pos+i == len(s):
                        return True
                    stack.append(pos+i)
        return False

if __name__ == '__main__':
    s = Solution()
    # print s.wordBreak('', {})
    print s.wordBreak('lintcode', {'lint':1, 'code':1})
    print s.wordBreak('lintt', {'lint':1, 'lintt':1})
    print s.wordBreak('lintcodefgh', {'lint':1, 'lintcode':1, 'code':1, 'f':1, 'fgh':1})
    print s.wordBreak('lintcodefghe', {'lint':1, 'lintcode':1, 'code':1, 'f':1, 'fgh':1})



