class Solution:
    def validPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [True] + [False] * n
        
        def same3(i) : return nums[i-3] == nums[i-2] == nums[i-1]
        def consecutive(i) : return nums[i-3] + 1 == nums[i-2] and nums[i - 2] + 1 == nums[i - 1]
        for i in range(2, n + 1) :
            dp[i] = dp[i - 2] and nums[i - 2] == nums[i - 1] or i >= 3 and dp[i - 3] and (same3(i) or consecutive(i))
        
        return dp[n]
        
