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
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        D = dict()
        food = set()
        table = set()
        for o in orders :
            k = (o[1], o[2])
            if k in D :
                D[k] += 1
            else :
                D[k] = 1
            food.add(o[2])
            table.add(int(o[1]))
        
        food = sorted(food)
        table = sorted(table)
        ret = [["Table"]]
        ret[0] += food
        for t in table :
            r = [str(t)]
            for f in food :
                k = (r[0], f)
                if k in D :
                    r.append(str(D[k]))
                else :
                    r.append(str(0))
            ret.append(r)
        return ret

