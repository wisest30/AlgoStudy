class Solution:
    def countHousePlacements(self, n: int) -> int:
        MOD = 1000000007
        dp = [1, 2]
        for i in range(2, n + 1) :
            dp[0], dp[1] = dp[1], (dp[0] + dp[1]) % MOD
        
        return dp[1] * dp[1] % MOD
