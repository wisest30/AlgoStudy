class Solution:
    def longestIdealString(self, s: str, k: int) -> int:
        dp = [0] * 26
        for c in s :
            i = ord(c) - ord('a')
            dp[i] = max(dp[j] + 1 for j in range(26) if abs(i - j) <= k)
        
        return max(dp)
