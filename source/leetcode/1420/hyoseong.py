from functools import lru_cache as lc
sys.setrecursionlimit(10 ** 9)

class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        MOD = 10**9 + 7

        @lru_cache(None)
        def dp_solve(n, k, max_val) :
            if n == 0 :
                return 1 if k ==  0 else 0
            if k < 0 :
                return 0
            if k == 0 :
                return max_val ** n % MOD

            ret = dp_solve(n-1, k, max_val) * max_val % MOD
            for i in range(max_val + 1, m+1):
                ret = (ret + dp_solve(n-1, k-1, i)) % MOD

            return ret
        
        ret = dp_solve(n, k, 0)
        return ret % MOD
