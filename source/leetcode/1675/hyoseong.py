from collections import deque as dq
from collections import defaultdict as dd
from collections import Counter as ct
from functools import lru_cache as lc
from heapq import heappush as hpush, heappop as hpop, heapify as hfy
from bisect import bisect_left, bisect_right
import itertools as it
import math

class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        n = len(nums)
        q = []
        min_val = 10 ** 10
        for i in range(n) :
            if nums[i] % 2 :
                nums[i] *= 2
            hpush(q, -nums[i])
            min_val = min(min_val, nums[i])
        
        ret = -q[0] - min_val
        while True :
            ret = min(ret, -q[0] - min_val)
            if (-q[0]) % 2 :
                break
            a = hpop(q)
            min_val = min(min_val, -a // 2)
            hpush(q, a//2)
        return ret
