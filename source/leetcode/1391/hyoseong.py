from collections import deque as dq
from collections import defaultdict as dd
from collections import Counter as ct
from functools import lru_cache as lc
from heapq import heappush as hpush, heappop as hpop, heapify as hfy
from bisect import bisect_left, bisect_right
import itertools as it
import math
import sys
sys.setrecursionlimit(10 ** 9)
####################################################################
class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        dy = [-1, 0, 0, 1]
        dx = [0, -1, 1, 0]

        n = len(grid)
        m = len(grid[0])

        visited = [[False] * m for _ in range(n)]
        def dfs(y, x) :
            if y == n - 1 and x == m - 1 :
                return True
            visited[y][x] = True

            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]

                if ny < 0 or ny >= n or nx < 0 or nx >= m :
                    continue
                if visited[ny][nx] :
                    continue

                if i == 0 and grid[y][x] in (2, 5, 6) and grid[ny][nx] in (2, 3, 4) and dfs(ny, nx) :
                    return True
                if i == 1 and grid[y][x] in (1, 3, 5) and grid[ny][nx] in (1, 4, 6) and dfs(ny, nx) :
                    return True
                if i == 2 and grid[y][x] in (1, 4, 6) and grid[ny][nx] in (1, 3, 5) and dfs(ny, nx) :
                    return True
                if i == 3 and grid[y][x] in (2, 3, 4) and grid[ny][nx] in (2, 5, 6) and dfs(ny, nx) :
                    return True
            
            return False

        return dfs(0, 0)