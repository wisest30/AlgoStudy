class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        dp = [nums[0]]
        queue = deque(dp)
        for i, n in enumerate(nums[1:]):
            if i >= k and queue[0] == dp[i - k]:
                queue.popleft()
                
            dp.append(max(n, n + queue[0]))
            while queue and queue[-1] < dp[-1]:
                queue.pop()
            queue.append(dp[-1])    
          
        return max(dp)
