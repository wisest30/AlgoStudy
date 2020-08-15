from collections import deque as dq
from collections import defaultdict as dd
from collections import Counter as ct
from functools import lru_cache as lc
from heapq import heappush as hpush, heappop as hpop, heapify as hfy
from bisect import bisect_left, bisect_right
import itertools as it
import math
import sys
sys.setrecursionlimit(10**9)
####################################################################
def solve() :
    n, m = map(int, input().split())
    P = list(map(int, input().split()))
    H = list(map(int, input().split()))
    edges = [[] for i in range(n)]
    for _ in range(n-1) :
        u, v = map(int, input().split())
        u, v = u-1, v-1
        edges[u].append(v)
        edges[v].append(u)

    def dfs(cur, prev) :
        ret = True
        happy = unhappy = 0
        for nxt in edges[cur] :
            if nxt == prev : continue
            sub_ret, sub_happy, sub_unhappy = dfs(nxt, cur)
            ret &= sub_ret
            happy += sub_happy
            unhappy += sub_unhappy
        
        unhappy += P[cur]
        h = happy - unhappy
        if H[cur] < h :
            ret = False
        if happy + unhappy < abs(H[cur]) :
            ret = False
        if H[cur] % 2 != h % 2 :
            ret = False

        happy += (H[cur] - h) // 2
        unhappy -= (H[cur] - h) // 2

        return ret, happy, unhappy
    
    print('YES' if dfs(0, -1)[0] else 'NO')

T = int(input())
for t in range(T) :
    solve()
