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
    def stringMatching(self, words: List[str]) -> List[str]:
        ret = list()
        n = len(words)
        for i in range(n):
            for j in range(n):
                if i != j and words[i] in words[j] :
                    ret.append(words[i])
                    break
        return ret
