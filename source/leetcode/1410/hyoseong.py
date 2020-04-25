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
    def entityParser(self, text: str) -> str:
        t = text.replace("&quot;", '"')
        t = t.replace("&apos;", "'")
        t = t.replace("&gt;", ">")
        t = t.replace("&lt;", "<")
        t = t.replace("&frasl;", "/")
        t = t.replace("&amp;", "&")
        return t
