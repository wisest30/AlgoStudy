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
    def reformat(self, s: str) -> str:
        A = []
        B = []
        for c in s :
            if c in "0123456789" :
                A.append(c)
            else :
                B.append(c)
        
        if len(A) < len(B) :
            A, B = B, A
        
        if len(A) - len(B) > 1 :
            return ""
        
        ret = []
        for i in range(len(A)):
            ret.append(A[i])
            if i < len(B) :
                ret.append(B[i])
        
        return "".join(ret)
