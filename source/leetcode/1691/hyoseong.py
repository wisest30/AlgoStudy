class Solution:
    def maxHeight(self, cuboids: List[List[int]]) -> int:
        cuboids.append([0, 0, 0])
        n = len(cuboids)
        for i in range(n) :
            cuboids[i].sort()
        cuboids.sort()

        dp = [0] * n
        for i in range(1, n) :
            for j in range(i) :
                if cuboids[i][0] >= cuboids[j][0] and cuboids[i][1] >= cuboids[j][1] and cuboids[i][2] >= cuboids[j][2] :
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2])
        
        return max(dp)
