class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        
        max_sum, temp_sum = float('-inf'), nums[0]
        for i in range(1, len(nums)):
            if nums[i - 1] < nums[i] and nums[i] < temp_sum + nums[i]:
                temp_sum += nums[i]
            else:      
                max_sum = max(temp_sum, max_sum)
                temp_sum = nums[i]
        max_sum = max(max_sum, temp_sum)
        return max_sum
            
            
