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
        def f(idx, diff_cnt, prev) :
            if idx == m :
                if diff_cnt == target - 1 :
                    return 0
                else :
                    return float('inf')
            
            if diff_cnt >= target :
                return float('inf')
            
            if A[idx] != 0 :
                if A[idx] == prev :
                    return f(idx + 1, diff_cnt, prev)
                else :
                    return f(idx + 1, diff_cnt + 1, A[idx])
            else :
                ret = float('inf')
                for i in range(n):
                    nxt_diff_cnt = diff_cnt + 1 if i + 1 != prev else diff_cnt
                    new_prev = i + 1
                    sub_ret = f(idx + 1, nxt_diff_cnt, new_prev) + cost[idx][i]
                    ret = min(ret, sub_ret)
                return ret

        ret = f(0, -1, -1)
        if ret == float('inf') :
            ret = -1
        return ret                    
                
