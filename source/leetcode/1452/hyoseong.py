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
        def isSubset(i, j) :
            return not (set(A[i]) - set(A[j]))

        def isSubsetOfAny(idx) :
            for i in range(len(A)) :
                if idx != i and isSubset(idx, i) :
                    return True
            return False

        ret = [i for i in range(len(A)) if not isSubsetOfAny(i)]
        return ret
