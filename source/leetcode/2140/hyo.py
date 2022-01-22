class Solution:
    def mostPoints(self, questions: List[List[int]]) -> int:        
        @lru_cache(None)
        def dp(i) : return 0 if i >= len(questions) else max(dp(i+1), questions[i][0] + dp(i + questions[i][1] + 1))
        return dp(0)
