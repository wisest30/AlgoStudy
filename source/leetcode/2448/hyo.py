class Solution:
    def minCost(self, nums: List[int], cost: List[int]) -> int:        
        n = len(nums)
        A = sorted(zip(nums, cost))
        
        m = (sum(cost) + 1) // 2
        cur, mid = 0, -1
        for p in A :
            cur += p[1]
            if m <= cur :
                mid = p[0]
                break
        
        ret = 0
        for p in A :
            ret += abs(mid - p[0]) * p[1]
        
        return ret
