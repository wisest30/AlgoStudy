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
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        n = len(arr)
        m = arr[(n-1) // 2]

        A = []
        for i in range(n) :
            A.append([-abs(arr[i] - m), -arr[i]])
        A.sort()
        ret = []
        for i in range(k) :
            ret.append(-A[i][1])
        return ret
        
