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
    def destCity(self, paths: List[List[str]]) -> str:
        S1 = set()
        S2 = set()
        for path in paths :
            S1.add(path[0])
            S2.add(path[1])
        
        S = S2 - S1
        ret = list(S)[0]
        return ret
