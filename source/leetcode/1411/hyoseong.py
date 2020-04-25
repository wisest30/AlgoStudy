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
    def numOfWays(self, n: int) -> int:
        MOD = 10**9 + 7

        A = []
        for i in range(3):
            for j in range(3):
                for k in range(3):
                    if i != j != k :
                        A.append(i + j * 3 + k * 9)

        @lc(None)
        def dp(i, prev) :
            if i == n :
                return 1

            ret = 0
            for cur in A :
                if prev != -1 :
                    if prev % 3 == cur % 3 :
                        continue
                    if prev // 3 % 3 == cur // 3 % 3 :
                        continue
                    if prev // 3 // 3 == cur // 3 // 3:
                        continue

                ret = (ret + dp(i+1, cur)) % MOD
            return ret
        
        return dp(0, -1)
