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

        n = len(points)
        Centers = []
        P = points
        for i in range(n):
            for j in range(i+1, n):
                d2 = dist2(P[i], P[j])
                d = d2 ** 0.5
                mx = (P[i][0] + P[j][0]) / 2
                my = (P[i][1] + P[j][1]) / 2
                if 4 * r * r < d2 :
                    continue
                elif 4 * r * r == d2 :
                    Centers.append([mx, my])
                else :
                    xc = mx + ((r * r - d2 / 4) ** 0.5) * (P[i][1] - P[j][1]) / d
                    yc = my + ((r * r - d2 / 4) ** 0.5) * (P[j][0] - P[i][0]) / d
                    Centers.append([xc, yc])
                    xc = mx - ((r * r - d2 / 4) ** 0.5) * (P[i][1] - P[j][1]) / d
                    yc = my - ((r * r - d2 / 4) ** 0.5) * (P[j][0] - P[i][0]) / d
                    Centers.append([xc, yc])

        ret = 1
        for center in Centers :
            candi = 0
            for i in range(n):
                if dist2(center, P[i]) <= r * r :
                    candi += 1
            ret = max(ret, candi)

        return ret
