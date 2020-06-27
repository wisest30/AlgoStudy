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
    def minDays(self, A: List[int], M: int, k: int) -> int:
        n = len(A)
        def check(m) :
            cnt = 0
            f_cnt = 0
            for i in range(n):
                if A[i] <= m :
                    cnt += 1
                else :
                    cnt = 0
                if cnt == k :
                    f_cnt += 1
                    cnt = 0
            return f_cnt >= M

        l, r = 0, 10 ** 9 + 1
        while l + 1 < r :
            m = (l+r) // 2
            if check(m) :
                r = m
            else :
                l = m
        
        if r > 10 ** 9 :
            ret = -1
        else :
            ret = r
        
        return ret
