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
    def minReorder(self, n: int, C: List[List[int]]) -> int:
        ADD = 10 ** 5
        edges = [[] for i in range(n)]
        for c in C :
            edges[c[0]].append(c[1])
            edges[c[1]].append(c[0] + ADD)

        self.ret = 0
        def dfs(cur, par) :
            for nxt in edges[cur] :
                if nxt == par or nxt - ADD == par : continue
                if nxt >= ADD :
                    #self.ret += 1
                    dfs(nxt - ADD, cur)
                else :
                    self.ret += 1
                    dfs(nxt, cur)
        
        dfs(0, -1)
        return self.ret
                
        
