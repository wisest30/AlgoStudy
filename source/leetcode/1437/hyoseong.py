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
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        P = []
        for i in range(len(nums)) :
            if nums[i] :
                P.append(i)
        
        for i in range(1, len(P)):
            if P[i] - P[i-1] <= k :
                return False

        return True            
