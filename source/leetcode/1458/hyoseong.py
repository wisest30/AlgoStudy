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
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        all_minus = True
        ret = -float("inf")
        for i in range(len(nums1)):
            for j in range(len(nums2)):
                if nums1[i] * nums2[j] >= 0 :
                    all_minus = False
                ret = max(ret, nums1[i] * nums2[j])
        
        if all_minus :
            return ret

        @lc(None)
        def f(first_idx, second_idx) :
            if first_idx == len(nums1) or second_idx == len(nums2) :
                return 0
            
            ret = f(first_idx + 1, second_idx)
            ret = max(ret, f(first_idx, second_idx + 1))
            ret = max(ret, f(first_idx + 1, second_idx + 1) + nums1[first_idx] * nums2[second_idx])
            return ret
        
        ret = f(0, 0)
        return ret
