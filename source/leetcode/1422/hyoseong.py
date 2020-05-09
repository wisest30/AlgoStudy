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
    def maxScore(self, s: str) -> int:
        n = len(s)
        ret = 0
        for i in range(1, n):
            s1 = s[:i]
            s2 = s[i:]
            ret = max(ret, s1.count('0') + s2.count('1'))
        
        return ret
