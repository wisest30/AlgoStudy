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
    def peopleIndexes(self, A: List[List[str]]) -> List[int]:
        n = len(A)
        S = [set() for i in range(n)]
        for i in range(n) :
            S[i] = set(A[i])
        
        res = [False] * n
        for i in range(n):
            for j in range(n):
                if i == j :
                    continue
                if (S[i] | S[j]) == S[j] :
                    res[i] = True
                    break
        
        ret = []
        for i in range(n) :
            if not res[i] :
                ret.append(i)
        return ret
