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
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: TreeNode) -> int:
        self.ret = 0
        cnt = [0] * 10
        def dfs(cur) :
            if not cur :
                return
            
            cnt[cur.val] += 1
            if cur.left :
                dfs(cur.left)
            if cur.right :
                dfs(cur.right)
            
            if not cur.left and not cur.right :
                odd_cnt = 0
                for c in cnt :
                    if c % 2 == 1 :
                        odd_cnt += 1
                if odd_cnt <= 1 :
                    self.ret += 1
            cnt[cur.val] -= 1
        
        dfs(root)
        return self.ret
