from collections import deque as dq
from collections import defaultdict as dd
from collections import Counter as ct
from functools import lru_cache as lc
from heapq import heappush as hpush, heappop as hpop, heapify as hfy
from bisect import bisect_left, bisect_right
import itertools as it
import math
import sys
#sys.setrecursionlimit(10**9)
input=sys.stdin.readline
####################################################################
def nCr(n, r) :
    return math.factorial(n) // math.factorial(r) // math.factorial(n-r)
 
def solve() :
    n = int(input())
    A = list(map(int, input().split()))
 
    PartialCount = [[0] * (n+1) for _ in range(n+1)]
    for i in range(n) :
        PartialCount[i+1] = PartialCount[i].copy()
        PartialCount[i+1][A[i]] += 1
    
    def get_cnt(val, left, right) :
        return PartialCount[right][val] - PartialCount[left][val]
    
    ret = 0
    for i in range(1, n+1) :
        cnt = get_cnt(i, 0, n)
        if cnt >= 4 :
            ret += nCr(cnt, 4)
    
    for j in range(1, n-2) :
        for k in range(j+1, n-1) :
            if A[j] == A[k] :
                continue
            cnt_i = get_cnt(A[k], 0, j)
            cnt_l = get_cnt(A[j], k+1, n)
            ret += cnt_i * cnt_l
    
    print(ret)
 
t = int(input())
for i in range(t) :
    solve()
