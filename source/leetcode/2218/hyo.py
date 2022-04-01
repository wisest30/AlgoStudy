class Solution:
    def maxValueOfCoins(self, piles: List[List[int]], k: int) -> int:
        for p in piles :
            for i in range(1, len(p)) :
                p[i] += p[i-1]

        @lru_cache(None)
        def recur(i, r) :
            if r == 0 or i == len(piles):
                return 0
            else :            
                return max([recur(i + 1, r)] + \
                       [recur(i + 1, r - (j+1)) + piles[i][j] for j in range(min(r, len(piles[i])))])
        
        return recur(0, k)
