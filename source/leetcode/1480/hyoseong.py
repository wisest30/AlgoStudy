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
    def runningSum(self, nums: List[int]) -> List[int]:
        ret = []
        for n in nums :
            if not ret :
                ret.append(n)
            else :
                ret.append(n + ret[-1])
        return ret
