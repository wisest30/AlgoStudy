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
    def findDiagonalOrder(self, A: List[List[int]]) -> List[int]:
        B = []
        for i in range(len(A)) :
            for j in range(len(A[i])) :
                B.append([i, j, A[i][j]])
        
        B.sort(key = lambda x : (x[0] + x[1]) * 1000000 + x[1])
        ret = []
        for b in B :
            ret.append(b[2])
        
        return ret
