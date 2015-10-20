#!/usr/bin/env python
# encoding: utf-8

# Question: 一个二维数组代表了一个岛. 周围都是海, 岛的左侧和上侧通向Pacific, 右侧和下侧通向Atlantic. 每个数字都代表了那个位置的海拔高度. 现在下雨了, 雨只有从海拔高的地儿能流向海拔低或者一样的地儿. 返回岛上的分水岭的点, 就是在某个/某些点上, 雨水既能流进Pacific, 又能流向Atlantic.

class Solution(object):
    # BFS
    def process(self, island, m, i, j):
        if m[i][j] != -1:
            return

        m[i][j] = 0

        if i-1 >= 0 and island[i-1][j] <= island[i][j]:
            if m[i-1][j] == -1:
                self.process(island, m, i-1, j)
            if m[i-1][j] == 1:
                m[i][j] = 1

        if i+1 < len(m) and island[i+1][j] <= island[i][j]:
            if m[i+1][j] == -1:
                self.process(island, m, i+1, j)
            if m[i+1][j] == 1:
                m[i][j] = 1

        if j-1 >= 0 and island[i][j-1] <= island[i][j]:
            if m[i][j-1] == -1:
                self.process(island, m, i, j-1)
            if m[i][j-1] == 1:
                m[i][j] = 1

        if j+1 < len(m[0]) and island[i][j+1] <= island[i][j]:
            if m[i][j+1] == -1:
                self.process(island, m, i, j+1)
            if m[i][j+1] == 1:
                m[i][j] = 1

    def solve(self, island):
        row = len(island)
        if row == 0:
            return []
        col = len(island[0])
        if col == 0:
            return []

        mat_alt = [[-1] * col for i in xrange(row)]
        mat_pac = [[-1] * col for i in xrange(row)]
        for i in xrange(row):
            mat_alt[i][col-1] = 1
            mat_pac[i][0]     = 1
        for j in xrange(col):
            mat_alt[row-1][j] = 1
            mat_pac[0][j]     = 1

        result = []
        for i in xrange(0, row):
            for j in xrange(0, col):
                self.process(island, mat_alt, i, j)
                self.process(island, mat_pac, i, j)
                if mat_alt[i][j] == 1 and mat_pac[i][j] == 1:
                    result.append([i,j])

        return result

if __name__ == '__main__':
    s = Solution()
    print s.solve([
        [1,7,2,3],
        [9,10,20,10],
        [4,1,30,5],
        [5,8,50,100]
    ])
