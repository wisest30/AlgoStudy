class Solution:
    def countVowelStrings(self, n: int) -> int:
        dp = [1] * 5
        for i in range(1, n) :
            ndp = [0] * 5
            for j in range(5) :
                for k in range(j+1) :
                    ndp[j] += dp[k]
            dp = ndp
        
        return sum(dp)
