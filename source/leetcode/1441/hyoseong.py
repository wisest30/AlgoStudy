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
    def buildArray(self, target: List[int], n: int) -> List[str]:
        A = []
        ret = []
        for i in range(1, n + 1) :
            if A == target : break
            A.append(i)
            ret.append("Push")
            if A[-1] not in target :
                A.pop()
                ret.append("Pop")
                
        return ret
