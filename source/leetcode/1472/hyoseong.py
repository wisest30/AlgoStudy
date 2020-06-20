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
class BrowserHistory:

    def __init__(self, homepage: str):
        self.A = [""] * 5000
        self.A[0] = homepage
        self.idx = 0
        self.cnt = 1

    def visit(self, url: str) -> None:
        self.idx += 1
        self.A[self.idx] = url
        self.cnt = self.idx + 1

    def back(self, steps: int) -> str:
        self.idx = max(0, self.idx - steps)
        return self.A[self.idx]

    def forward(self, steps: int) -> str:
        self.idx = min(self.cnt - 1, self.idx + steps)
        return self.A[self.idx]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)
