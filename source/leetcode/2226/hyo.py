class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        def check(m) :
            cnt = 0
            for c in candies :
                cnt += c // m
            return cnt >= k
            
        l, r = 0, 10 ** 15
        while l + 1 < r :
            m = (l + r) // 2
            if check(m) :
                l = m
            else :
                r = m
        
        return l
