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
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        words = list(sentence.split())
        ret = -1
        for i in range(len(words)) :
            if words[i].startswith(searchWord) :
                ret = i + 1
                break
        return ret
