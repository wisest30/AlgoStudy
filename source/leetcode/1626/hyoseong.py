class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        A = list(zip(ages, scores)) + [(-1, -1)]
        A.sort()
        n = len(A)
        
        dp = [0] * n
        for i in range(1, n) :
            for j in range(i) :
                if A[j][0] == A[i][0] or A[j][1] <= A[i][1] :
                    dp[i] = max(dp[i], dp[j] + A[i][1])
        
        return max(dp)
        
