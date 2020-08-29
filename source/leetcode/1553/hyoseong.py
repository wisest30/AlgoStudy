class Solution:
    def minDays(self, n: int) -> int:
        self.depth = 0
        @lru_cache(None)
        def dp(n) :
            if n == 0 : return 0
            if self.depth > 100 : return inf
            
            self.depth += 1
            
            ret = inf
            if n % 3 == 0 : ret = min(ret, dp(n // 3) + 1)
            if n % 2 == 0 : ret = min(ret, dp(n // 2) + 1)
            ret = min(ret, dp(n-1) + 1)

            self.depth -= 1
            return ret
    
        return dp(n)
