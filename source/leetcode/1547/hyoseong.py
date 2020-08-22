class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.sort()
        @lru_cache(None)
        def dp(l, r) :
            if l + 1 == r : return 0
            ret = float('INF')
            for i in range(l+1, r) :
                cur_len = (cuts[r] if r < len(cuts) else n) - (cuts[l] if l >= 0 else 0)
                ret = min(ret, dp(l, i) + dp(i, r) + cur_len)
            return ret
        
        return dp(-1, len(cuts))
