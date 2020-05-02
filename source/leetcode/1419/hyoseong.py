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
    def minNumberOfFrogs(self, croakOfFrogs: str) -> int:
        s = "croak"
        A = [0] * len(s)
        ret = 0
        for c in croakOfFrogs :
            i = s.index(c)
            A[i] += 1
            if i and A[i-1] < A[i] :
                return -1
            
            ret = max(ret, A[0] - A[-1])
        
        if A[0] != A[-1] :
            return -1
        
        return ret
