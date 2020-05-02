class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        mod = 10 ** 9 + 7
        
        @lru_cache(None)
        def count(n, k, upper):
            if n < k or k < 0:
                return 0
                
            if n == 0:
                return 1
            
            return (sum(count(n - 1, k, upper) for i in range(1, upper + 1)) + 
                    sum(count(n - 1, k - 1, i) for i in range(upper + 1, m + 1))) % mod
                
        return count(n, k, 0) 
