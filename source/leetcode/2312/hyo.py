class Solution:
    def sellingWood(self, r: int, c: int, prices: List[List[int]]) -> int:
        A = [[0] * (c + 1) for _ in range(r + 1)]
        for p in prices :
            A[p[0]][p[1]] = p[2]
        
        dp = [[0] * (c + 1) for _ in range(r + 1)]
        
        for i in range(1, r + 1) :
            for j in range(1, c + 1) :
                dp[i][j] = A[i][j]
                for k in range(1, i // 2 + 1) :
                    dp[i][j] = max(dp[i][j], dp[k][j] + dp[i - k][j])
                for k in range(1, j // 2 + 1) :
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[i][j - k])
        
        return dp[r][c]
