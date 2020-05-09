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
    def maxScore(self, A: List[int], k: int) -> int:
        n = len(A)
        cur = sum(A[:k])
        ret = cur
        for i in range(k):
            cur = cur + A[-i-1] - A[k-1-i]
            ret = max(ret, cur)

        return ret            
