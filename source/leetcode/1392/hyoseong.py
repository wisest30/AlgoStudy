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
    def longestPrefix(self, s: str) -> str:
        def get_pi(s) :
            n, j = len(s), 0
            pi = [0] * n
            for i in range(1, n):
                while j and s[i] != s[j] :
                    j = pi[j-1]
                if s[i] == s[j] :
                    j += 1
                    pi[i] = j
            return pi
        
        pi = get_pi(s)
        return s[:pi[-1]]