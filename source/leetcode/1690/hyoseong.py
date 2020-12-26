class Solution:
    def stoneGameVII(self, stones: List[int]) -> int:
        PS = [0] * (len(stones) + 1)
        for i in range(1, len(PS)) :
            PS[i] = PS[i-1] + stones[i-1]
        
        n = len(stones)
        dp = [[0] * (n + 1) for _ in range(n+1)]
        
        for length in range(2, n+1) :
            for left in range(n) :
                right = left + length
                if right > n :
                    break

                dp[left][right] = -dp[left+1][right] + PS[right] - PS[left+1]
                dp[left][right] = max(dp[left][right], -dp[left][right-1] + PS[right-1] - PS[left])
        
        return dp[0][n]
