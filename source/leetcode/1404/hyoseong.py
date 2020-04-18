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
    def numSteps(self, s: str) -> int:
        x = int(s, 2)
        ret = 0
        while x != 1 :
            if x % 2 == 0 :
                x //= 2
                ret += 1
            else :
                x += 1
                ret += 1
        
        return ret
