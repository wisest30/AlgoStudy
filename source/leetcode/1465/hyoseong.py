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
    def maxArea(self, R: int, C: int, HC: List[int], VC: List[int]) -> int:
        MOD = 10 ** 9 + 7
        HC.sort()
        VC.sort()
        HC.append(R)
        VC.append(C)
        max_h = HC[0]
        max_v = VC[0]
        for i in range(1, len(HC)):
            max_h = max(max_h, HC[i] - HC[i-1])
        for i in range(1, len(VC)):
            max_v = max(max_v, VC[i] - VC[i-1])
        
        return max_h * max_v % MOD
            
            
