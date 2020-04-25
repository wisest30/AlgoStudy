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
    def processQueries(self, Q: List[int], m: int) -> List[int]:
        A = [i + 1 for i in range(m)]
        ret = []
        for q in Q :
            r = A.index(q)
            ret.append(r)
            A.remove(q)
            A.insert(0, q)
        return ret
