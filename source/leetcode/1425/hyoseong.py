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
    def constrainedSubsetSum(self, A: List[int], k: int) -> int:
        n = len(A)
        q = []
        ret = -float("inf")
        for i in range(n):
            candi = A[i]
            while q :
                a = hpop(q)
                val, prev_i = -a[0], a[1]

                if i - prev_i > k :
                    continue

                if val > 0 :
                    candi += val

                hpush(q, a)
                break

            ret = max(ret, candi)
            hpush(q, [-candi, i])

        return ret            
            
