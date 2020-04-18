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
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        A = [['a', a], ['b', b], ['c', c]]
        ret = []

        A.sort(key = lambda x : -x[1])
        while A[0][1] :
            if len(ret) >= 2 and ret[-1] == ret[-2] and ret[-1] == A[0][0] :
                if A[1][1] == 0 :
                    break
                A[1][1] -= 1
                ret.append(A[1][0])
            else :
                A[0][1] -= 1
                ret.append(A[0][0])
            A.sort(key = lambda x : -x[1])
        
        return "".join(ret)
