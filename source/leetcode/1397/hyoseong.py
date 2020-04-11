from functools import lru_cache as lc
import sys
sys.setrecursionlimit(10 ** 9)
####################################################################
class Solution:
    def findGoodStrings(self, n: int, s1: str, s2: str, evil: str) -> int:
        def get_pi(s) :
            n, j = len(s), 0
            pi = [0] * n
            for i in range(1, n):
                while j and s[i] != s[j] :
                    j = pi[j-1]
                if s[i] == s[j] :
                    j += 1
                    pi[i] = j
            return pi
        
        m, pi = len(evil), get_pi(evil)
        @lc(None)
        def dp(s, i, j, large) :
            n = len(s)
            if j == m :
                return 0
            if i == n :
                return 1
            
            ret = 0
            for c in "abcdefghijklmnopqrstuvwxyz" :
                if not large and c > s[i] :
                    break
                nxt_j, nxt_large = j, large
                while nxt_j and c != evil[nxt_j] :
                    nxt_j = pi[nxt_j-1]
                if c == evil[nxt_j] :
                    nxt_j += 1
                if s[i] != c :
                    nxt_large = True
                ret += dp(s, i+1, nxt_j, nxt_large)
            return ret
        
        ret = dp(s2, 0, 0, False) - dp(s1, 0, 0, False)
        if evil not in s1 :
            ret += 1
        return ret % (10 ** 9 + 7)
