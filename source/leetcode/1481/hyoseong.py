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
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        A = list(ct(arr).values())
        A.sort()
        ret = 0
        for i in range(len(A)):
            if k >= A[i] :
                k -= A[i]
            else :
                ret += 1
        return ret
