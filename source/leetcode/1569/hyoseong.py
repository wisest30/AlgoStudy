from collections import deque as dq
from collections import defaultdict as dd
from collections import Counter as ct
from functools import lru_cache as lc
from heapq import heappush as hpush, heappop as hpop, heapify as hfy
from bisect import bisect_left, bisect_right
import itertools as it
import math
import sys
sys.setrecursionlimit(10**9)
####################################################################
class Solution:
    def solve(self, nums):
        if len(nums) <= 1 :
            return 1
        ret = 0
        MOD = 10 ** 9 + 7
        n = len(nums)
        
        l = []
        r = []
        for i in range(1, n) :
            if nums[i] < nums[0] :
                l.append(nums[i])
            else :
                r.append(nums[i])
        
        sub_ret1 = self.solve(l)
        sub_ret2 = self.solve(r)
        ret = sub_ret1 * sub_ret2 * comb(len(l) + len(r), len(l)) % MOD
        return ret
    def numOfWays(self, nums: List[int]) -> int:
        return self.solve(nums) - 1
