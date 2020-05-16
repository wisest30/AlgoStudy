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
    def kthSmallest(self, mat: List[List[int]], K: int) -> int:
        n = len(mat)
        m = len(mat[0])

        dp = mat[0][:]
        dp.sort()
        for i in range(1, n):
            while len(dp) > K :
                dp.pop()
            
            dp2 = []
            for j in range(m):
                for k in range(len(dp)):
                    dp2.append(mat[i][j] + dp[k])
            dp2.sort()
            dp, dp2 = dp2, dp
        
        return dp[K-1]
