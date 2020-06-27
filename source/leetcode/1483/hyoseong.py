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
class TreeAncestor:

    def __init__(self, n: int, parent: List[int]):
        self.P = [[-1] * n for i in range(32)]
        self.P[0] = parent
        for i in range(1, 32):
            for j in range(n):
                if self.P[i-1][j] == -1 :
                    self.P[i][j] = -1
                else :
                    self.P[i][j] = self.P[i-1][self.P[i-1][j]]
    def getKthAncestor(self, node: int, k: int) -> int:
        while k :
            sub = 1
            i = 0
            while sub < k :
                sub *= 2
                i += 1
            if sub > k :
                i -= 1
                sub //= 2
            if node == -1 :
                break
            node = self.P[i][node]
            k -= sub
        return node
            


# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n, parent)
# param_1 = obj.getKthAncestor(node,k)
