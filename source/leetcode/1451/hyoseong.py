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
    def arrangeWords(self, text: str) -> str:
        A = sorted(text.lower().split(' '), key = lambda x : len(x))
        A[0] = A[0][0].upper() + A[0][1:]
        return " ".join(A)
