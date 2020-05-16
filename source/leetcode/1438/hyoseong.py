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
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        n = len(nums)
        max_que = []
        min_que = []

        left = right = ret = 0
        while right < n :
            hpush(max_que, [-nums[right], right])
            hpush(min_que, [nums[right], right])

            while True :
                max_val, idx = hpop(max_que)
                max_val *= -1
                if idx < left :
                    continue
                elif max_val - nums[right] > limit :
                    left = idx + 1
                    continue
                else :
                    hpush(max_que, [-max_val, idx])
                    break
            
            while True :
                min_val, idx = hpop(min_que)
                if idx < left :
                    continue
                elif nums[right] - min_val > limit :
                    left = idx + 1
                    continue
                else :
                    hpush(min_que, [min_val, idx])
                    break
            
            ret = max(ret, right + 1 - left)
            right += 1
        
        return ret
                
