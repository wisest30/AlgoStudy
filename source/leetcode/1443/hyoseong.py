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
    def minTime(self, n: int, E: List[List[int]], hasApple: List[bool]) -> int:
        edges = [[] for i in range(n)]
        for e in E :
            edges[e[0]].append(e[1])
            edges[e[1]].append(e[0])
        
        def dfs(cur, par) :
            if not edges[cur] :
                return 0

            ret = 0
            for nxt in edges[cur] :
                if nxt == par :
                    continue

                sub_ret = dfs(nxt, cur)
                if sub_ret == 0 :
                    if not hasApple[nxt] :
                        continue
                    else :
                        ret += 2
                else :
                    ret += sub_ret + 2
            
            return ret
        
        return dfs(0, -1)
        
