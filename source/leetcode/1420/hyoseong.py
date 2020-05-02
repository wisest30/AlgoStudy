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
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        MOD = 10**9 + 7

        @lc(None)
        def dp(n, k, max_val) :
            if n == 0 :
                if k == 0 :
                    return 1
                else :
                    return 0
            if k < 0 :
                return 0
            if k == 0 :
                return max_val ** n % MOD

            ret = 0
            for i in range(1, m+1):
                if i <= max_val :
                    ret = (ret + dp(n-1, k, max_val)) % MOD
                else :
                    ret = (ret + dp(n-1, k-1, i)) % MOD
            return ret
        
        ret = dp(n, k, 0)
        return ret % MOD
