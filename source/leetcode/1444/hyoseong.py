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
    def ways(self, pizza: List[str], k: int) -> int:
        MOD = 10 ** 9 + 7
        R, C = len(pizza), len(pizza[0])
        A = [[1 if pizza[i][j] == 'A' else 0 for j in range(C)] for i in range(R)]

        S = [[0] * (C + 1) for _ in range(R + 1)]
        for i in range(R) :
            for j in range(C) :
                S[i+1][j+1] = S[i][j+1] + S[i+1][j] - S[i][j] + A[i][j]
        
        def get_cnt(y0, x0, y1, x1) :
            return S[y1][x1] - S[y0][x1] - S[y1][x0] + S[y0][x0]

        @lc(None)
        def dp_solve(row, col, remain_cut) :
            if remain_cut == 0 :
                return 1
            
            ret = 0
            for i in range(row + 1, R):
                give_cnt = get_cnt(row, col, i, C)
                remain_cnt = get_cnt(i, col, R, C)

                if give_cnt < 1 or remain_cnt < 1 : continue

                ret += dp_solve(i, col, remain_cut - 1)
                ret %= MOD
                
            for i in range(col + 1, C):
                give_cnt = get_cnt(row, col, R, i)
                remain_cnt = get_cnt(row, i, R, C)

                if give_cnt < 1 or remain_cnt < 1 : continue

                ret += dp_solve(row, i, remain_cut - 1)
                ret %= MOD
            
            return ret
        
        ret = dp_solve(0, 0, k-1)
        return ret % MOD
