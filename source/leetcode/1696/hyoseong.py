from heapq import heappush as hpush, heappop as hpop, heapify as hfy
class Solution:
    def maxResult(self, nums: List[int], k: int) -> int:
        n = len(nums)
        dp = [0] * n
        dp[0] = nums[0]
        q = [[-dp[0], 0]]
        
        for i in range(1, n) :
            while q and q[0][1] + k < i :
                hpop(q)
            
            dp[i] = nums[i] - q[0][0]
            hpush(q, [-dp[i], i])
        
        return dp[n-1]
