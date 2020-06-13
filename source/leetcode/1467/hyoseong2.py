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
        
        def f(idx, box1, box2) :
            if idx == k :
                if sum(box1) != n :
                    return 0

                cnt1 = n - box1.count(0)
                cnt2 = n - box2.count(0)                
                if cnt1 != cnt2 :
                    return 0
                
                ret = math.factorial(n) ** 2
                for i in range(k) :
                    ret //= math.factorial(box1[i])
                    ret //= math.factorial(box2[i])
                return ret
            
            ret = 0
            for i in range(A[idx] + 1) :
                box1.append(i)
                box2.append(A[idx] - i)
                ret += f(idx + 1, box1, box2)
                box1.pop()
                box2.pop()
            
            return ret
        
        total_cnt = math.factorial(2 * n)
        for i in range(k):
            total_cnt //= math.factorial(A[i])
        
        ret = f(0, [], []) / total_cnt
        return ret

