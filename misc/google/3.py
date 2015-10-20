#!/usr/bin/env python
# encoding: utf-8

# Question:
# 给一个String，只包含d和i, d表示数值下降，i表示升高。从1到9之间选择一串数字，每个数字只用一次，找到一个符合String pattern的序列。String长度不超过8，肯定能找到一个valid序列。
# 比如：iii -> 1234
#       ididid -> 1835294
#
# 解法说明：
# 遍历输入字符串，如果是i，pass；如果是d，找到连续的d序列，假设序列为：s[i:j]（即s[i],s[i+1]...s[j-1]为连续d序列），则将array中对应的数字array[i:j+1]逆序，最终返回对应的数字序列即可。

class Solution(object):
    def reverse(self, array, istart, iend):
        while istart < iend:
            array[istart], array[iend] = array[iend], array[istart]
            istart += 1
            iend -= 1

    def solve(self, s):
        if len(s) == 0:
            return []

        array = [1, 2, 3, 4, 5, 6, 7, 8, 9]
        istart, iend = -1, -1
        for i in xrange(len(s)):
            if s[i] == 'i':
                if istart != -1:
                    iend = i
                    self.reverse(array, istart, iend)
                    istart = -1
                    iend = -1
            else:
                if istart == -1:
                    istart = i
        if istart != -1:
            iend = len(s)
            self.reverse(array, istart, iend)

        return array[:len(s)+1]

if __name__ == '__main__':
    s = Solution()
    print s.solve('iii')
    print s.solve('idd')
    print s.solve('ididid')
    print s.solve('ddiii')
    print s.solve('ddiiid')
    print s.solve('iiid')
    print s.solve('dddddddd')
