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
    def minCost(self, A: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        @lc(None)
        def f(idx, neighborhoods, prev) :
            if idx == m :
                return 0 if neighborhoods == target else float('inf')
            if neighborhoods > target :
                return float('inf')
            
            if A[idx] != 0 :
                return f(idx + 1, neighborhoods + (A[idx] != prev), A[idx])
            else :
                ret = float('inf')
                for i in range(n):
                    candi = f(idx + 1, neighborhoods + (i + 1 != prev), i + 1) + cost[idx][i]
                    ret = min(ret, candi)
                return ret

        ret = f(0, 0, -1)
        return -1 if ret == float('inf') else ret
                
