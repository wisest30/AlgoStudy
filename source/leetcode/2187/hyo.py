class Solution:
    def minimumTime(self, time: List[int], totalTrips: int) -> int:
        l, r = 0, 10 ** 18
        while l + 1 < r :
            m = (l + r) // 2
            if sum(m // t for t in time) >= totalTrips :
                r = m
            else :
                l = m
        
        return r
