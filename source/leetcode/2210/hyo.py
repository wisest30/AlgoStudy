class Solution:
    def countHillValley(self, nums: List[int]) -> int:
        nums = [nums[i] for i in range(len(nums)) if i == 0 or nums[i] != nums[i-1]]
        return sum(1 for i in range(1, len(nums) - 1) \
                   if nums[i] > max(nums[i-1], nums[i+1]) or nums[i] < min(nums[i-1], nums[i+1]))
