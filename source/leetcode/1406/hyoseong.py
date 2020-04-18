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
    def stoneGameIII(self, A: List[int]) -> str:
        n = len(A)
        @lc(None)
        def f(t, i) :
            if i == n :
                return 0

            ret = -f(t ^ 1, i + 1) + A[i]
            if i + 1 < n :
                ret = max(ret, -f(t ^ 1, i + 2) + A[i] + A[i+1])
            if i + 2 < n :
                ret = max(ret, -f(t ^ 1, i + 3) + A[i] + A[i+1] + A[i+2])

            #print(t, i, ret)
            return ret
        
        ret = f(0, 0)
        if ret > 0 :
            return "Alice"
        elif ret == 0 :
            return "Tie"
        else :
            return "Bob"

