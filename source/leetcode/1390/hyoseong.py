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
    def sumFourDivisors(self, nums: List[int]) -> int:
        def f(x) :
            S = set()
            i = 1
            while i * i <= x and len(S) <= 4:
                if x % i == 0 :
                    S.add(i)
                    S.add(x // i)
                i += 1

            return sum(S) if len(S) == 4 else 0
        
        ret = 0
        for x in nums :
            ret += f(x)
        
        return ret

                