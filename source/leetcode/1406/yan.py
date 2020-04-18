class Solution:
    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        dp = [-float('inf')] * n + [0]
        
        for i in reversed(range(n)):
            for j in range(3):
                if i + j >= n:
                    continue
                dp[i] = max(dp[i], sum(stoneValue[i: i + j + 1]) - dp[i + j + 1])
                
        return 'Bob' if dp[0] < 0 else 'Alice' if dp[0] > 0 else 'Tie'
