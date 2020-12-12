from collections import deque as dq
from collections import defaultdict as dd
from collections import Counter as ct
from functools import lru_cache as lc
from heapq import heappush as hpush, heappop as hpop, heapify as hfy
from bisect import bisect_left, bisect_right
import itertools as it
import math
import sys
sys.setrecursionlimit(10**5)
####################################################################
class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        A = []
        q = []
        for i in range(n - k + 1) :
            hpush(q, [nums[i], i])
        
        A.append(hpop(q))
        for i in range(n - k + 1, n) :
            while q and q[0][1] < A[-1][1] :
                hpop(q)
            hpush(q, [nums[i], i])
            A.append(hpop(q))
        
        ret = []
        for a in A :
            ret.append(a[0])
        return ret
