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
    def numPoints(self, points: List[List[int]], r: int) -> int:
        def dist2(p1, p2) :
            return (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2

        def getCircleIncludeTwoPoint(i, j) :
            d2 = dist2(points[i], points[j])
            d = d2 ** 0.5
            mx = (points[i][0] + points[j][0]) / 2
            my = (points[i][1] + points[j][1]) / 2

            if 4 * r * r < d2 :
                return []
            elif 4 * r * r == d2 :
                return [[mx, my]]
            else :
                dc0 = ((r * r - d2 / 4) ** 0.5) * (points[j][0] - points[i][0]) / d
                dc1 = ((r * r - d2 / 4) ** 0.5) * (points[i][1] - points[j][1]) / d
                return [[mx + dc1, my + dc0], [mx - dc1, my - dc0]]
        
        def getCntIncludingPoint(c) :
            return len([1 for i in range(len(points)) if dist2(c, points[i]) <= r ** 2])

        Centers = []
        for i in range(len(points)):
            for j in range(i+1, len(points)):
                Centers += getCircleIncludeTwoPoint(i, j)

        ret = max([1] + [getCntIncludingPoint(c) for c in Centers])
        return ret
