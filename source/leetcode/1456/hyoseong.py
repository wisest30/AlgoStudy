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
    def maxVowels(self, s: str, k: int) -> int:
        vowels = "aeiou"
        cur_cnt = 0
        for i in range(k) :
            if s[i] in vowels :
                cur_cnt += 1
        ret = cur_cnt

        for i in range(k, len(s)) :
            if s[i] in vowels :
                cur_cnt += 1
            if s[i-k] in vowels :
                cur_cnt -= 1
            ret = max(ret, cur_cnt)
        return ret
