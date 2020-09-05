class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        n = len(piles) // 3
        piles.sort()
        
        ret = sum([piles[i] for i in range(3*n - 2, n - 2, -2)])
        return ret
