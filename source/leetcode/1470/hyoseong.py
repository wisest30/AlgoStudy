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
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        n = len(nums) // 2
        ret = []
        for i in range(n) :
            ret.append(nums[i])
            ret.append(nums[i+n])
        return ret
