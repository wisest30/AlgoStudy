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
        A = list(text.split(' '))
        A.sort(key = lambda x : len(x))

        for i in range(len(A)) :
            if i == 0 :
                A[i] = A[i][0].upper() + A[i][1:]
            else :
                A[i] = A[i].lower()

        ret = " ".join(A)
        return ret
