#!/usr/bin/env python
# encoding: utf-8

# Question: http://www.lintcode.com/en/problem/wildcard-matching/

class Solution:
    def match_with_recursion(self, s, p):
        if len(s) == 0:
            if len(p) == 0:
                return True
            else:
                if p[0] == '*':
                    j = 1
                    while j < len(p) and p[j] == '*':
                        j += 1
                    if j < len(p):
                        return False
                    else:
                        return True
                else:
                    return False
        else:
            if len(p) == 0:
                return False
            else:
                if p[0] == '?' or p[0] == s[0]:
                    return self.isMatch(s[1:], p[1:])
                elif p[0] == '*':
                    j = 1
                    while j < len(p) and p[j] == '*':
                        j += 1
                    return self.isMatch(s, p[j:]) or self.isMatch(s[1:], p[j:]) or self.isMatch(s[1:], p)
                else:
                    return False

    def match_with_dp_with_2dmatrix(self, s, p):
        row = len(s)
        col = len(p)
        dp = [[False] * (col+1) for i in xrange(row+1)]

        dp[0][0] = True
        for i in xrange(1, row+1):
            dp[i][0] = False
        for j in xrange(1, col+1):
            dp[0][j] = p[j-1] == '*' and dp[0][j-1]

        for i in xrange(1, row+1):
            for j in xrange(1, col+1):
                if p[j-1] == '*':
                    dp[i][j] = dp[i-1][j-1] or dp[i-1][j] or dp[i][j-1]
                else:
                    dp[i][j] = dp[i-1][j-1] and (p[j-1] == '?' or p[j-1] == s[i-1])

        return dp[row][col]

    def match_with_backtrack(self, s, p):
        size_s = len(s)
        size_p = len(p)
        ptr_s, ptr_p = 0, 0
        saved_s, saved_p = None, None
        while ptr_s < size_s:
            if ptr_p < size_p and (s[ptr_s] == p[ptr_p] or p[ptr_p] == '?'):
                ptr_s, ptr_p = ptr_s+1, ptr_p+1
            elif ptr_p < size_p and p[ptr_p] == '*':
                saved_s, saved_p = ptr_s+1, ptr_p
                ptr_p += 1
            elif saved_s:
                ptr_s, ptr_p = saved_s, saved_p
            else:
                return False
        return p[ptr_p:].count('*') == size_p - ptr_p

    """
    @param s: A string
    @param p: A string includes "?" and "*"
    @return: A boolean
    """
    def isMatch(self, s, p):
        # return self.match_with_dp_with_2dmatrix(s, p)
        return self.match_with_backtrack(s, p)


if __name__ == '__main__':
    s = Solution()
    print s.isMatch("aab", "c*a*b")
    print s.isMatch("aa", "****a*****b***")
    print s.isMatch("aa", "*a*")
    print s.isMatch("aa", "*a**")
    print s.isMatch("aa", "*")
    print s.isMatch("abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb", "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb")
