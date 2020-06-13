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
def nCr(n, r) :
    return math.factorial(n) // math.factorial(r) // math.factorial(n-r)

class Solution:
    def getProbability(self, A: List[int]) -> float:
        n = sum(A) // 2
        k = len(A)
        
        @lc(None)
        def f(idx, k1, k2, prev_cnt) :
            if idx == k :
                if prev_cnt != n :
                    return 0
                if k1 == 0 and k2 == 0 :
                    return 1
                else :
                    return 0
            
            ret = 0
            remain_total = sum(A[idx:])
            for i in range(A[idx] + 1):
                nxt_k1 = k1
                nxt_k2 = k2
                nxt_prev_cnt = prev_cnt + i
                if i > 0 :
                    nxt_k1 -= 1
                if i < A[idx] :
                    nxt_k2 -= 1
                
                nxt_cnt = n - prev_cnt
                if nxt_cnt < i or remain_total < nxt_cnt or A[idx] < i : continue
                if remain_total - nxt_cnt < A[idx] - i : continue

                sub_ret = f(idx + 1, nxt_k1, nxt_k2, nxt_prev_cnt)
                ret += sub_ret * nCr(nxt_cnt, i) * nCr(remain_total - nxt_cnt, A[idx] - i)

            return ret
        
        total_cnt = math.factorial(2 * n)
        for i in range(k):
            total_cnt //= math.factorial(A[i])
        
        ret = 0
        for i in range(1, k + 1):
            ret += f(0, i, i, 0)
        ret /= total_cnt
        
        return ret

