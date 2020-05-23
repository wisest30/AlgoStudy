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
    def countTriplets(self, arr: List[int]) -> int:
        S = [0] * (len(arr) + 1)
        for i in range(1, len(S)) :
            S[i] = S[i-1] ^ arr[i-1]
        
        n = len(arr)
        ret = 0
        for i in range(n):
            for j in range(i + 1, n):
                for k in range(j, n) :
                    a = S[j] ^ S[i]
                    b = S[k+1] ^ S[j]
                    if a == b :
                        ret += 1

        return ret                
